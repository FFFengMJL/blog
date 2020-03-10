let search = document.getElementById('searchArea');
let li = document.getElementById('list');
let lastText = '';
let p = document.querySelector('p');
const testOb = {names : '1'};

function deleteListAll() {
    while(li.childElementCount != 0) {
        li.removeChild(li.lastChild);
    }
}

async function getContent(content) {
    deleteListAll();
    p.innerText = 'now searching...';
    fetch(`https://swapi.co/api/people/?search=${content}`)
    .then(res => { // 把内容添加到 list 中
        res.text()
        .then(text => {
            let names = JSON.parse(text).results;
            if (names.length == 0) {
                p.innerText = 'nothing found';
                return;
            }
            else p.innerText = '';
            for (name in names) {
                let newList = document.createElement('li');
                newList.innerText = names[name].name;
                li.appendChild(newList);
            }    
        })
        .catch(err => { return err; });
    })
    .catch(err => { return err; });
}

const times = {
    time : 0, // 代表间隔 100ms 的次数
    null : false // 代表是否搜索过
};

window.onload = function () {
    setInterval(function () {
        if(search.value != lastText) { // 搜索的东西改变了
            times.null = false;
            times.time = 0;
            p.innerText = '';
            lastText = search.value;
        }
        else { // 没有变化
            if (!times.null) { // false 代表没有搜索过
                times.time++;
                lastText = search.value;
                if (times.time == 5) {
                    times.time = 0;
                    times.null = true;
                    // console.log(lastText)
                    getContent(lastText);
                }
            }
        }
    }, 100);
};