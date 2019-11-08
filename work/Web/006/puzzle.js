function initial(gameMap, hidden, blockSize, borderSize, topPx, win) {
    var map = document.getElementById("map");
    for (var i = 0; i < 4; i++){
        for (var j = 0; j < 4; j++) {
            var block = document.createElement("div");
            block.setAttribute("class", "block");
            block.style.width = blockSize + "px";
            block.style.height = blockSize + "px";
            block.style.left = j * (blockSize + borderSize) + topPx + "px";
            block.style.top = i * (blockSize + borderSize) + topPx + "px";
            block.style.backgroundImage = "url(./panda.jpg)";
            block.style.backgroundPositionX = "-" + block.style.left;
            block.style.backgroundPositionY = "-" + block.style.top;
            // block.style.visibility = "hidden";
            // block.innerText = j + i * 4;
            block.id = i * 4 + j;
            block.mapId = block.id;
            block.addEventListener("click", function(event) {
                // console.log("addEventListener");
                if (win == true) return;
                if (this.style.visibility == "hidden") return;
                var blocks = document.getElementsByClassName("block");
                if (surroundHidden(this.id, hidden.id)) {
                    var posX = this.style.left;
                    var posY = this.style.top;
                    var thisUsedPos = this.mapId;
                    this.mapId = blocks[hidden.id].mapId;
                    blocks[hidden.id].mapId = thisUsedPos;
                    this.style.left = blocks[hidden.id].style.left;
                    this.style.top = blocks[hidden.id].style.top;
                    blocks[hidden.id].style.left = posX;
                    blocks[hidden.id].style.top = posY;
                    // console.log("changeed");
                    for (var i = 0; i < gameMap.pos.length; i++) {
                        if (gameMap.pos[i] != i) return;
                    }
                    alert("你赢了");
                }
            });
            map.appendChild(block);
        }
    }
}

Array.prototype.shuffle = function() { // 打乱数组
    var array = this;
    var m = array.length,
        t, i;
    while (m) {
        i = Math.floor(Math.random() * m--);
        t = array[m];
        array[m] = array[i];
        array[i] = t;
    }
    return array;
}

function solvability(order, size){ // 判断能够还原
    var a;
    var count = 0;
    var m = 0;
    var n = 0;
    
    var len = order.length;
    size = size || 3;
    //[0,1,2,3,4,5,7,6,8]
    for(var i=0; i<len; i++){
        a = order[i];
        

        //if( a == 8){
        if(a == size*size-1){
　　　　 
            m = parseInt(i/size);
            n = parseInt(i%size);
        }
            
        for(var j=i+1; j<len; j++){
            
            if(order[j]<a){
                count++;
            }
        }
    }
    count += m;
    count += n;
    return count%2 == 0;
}


// function getRandomInt(min, max) { // 获得随机整数
//     min = Math.ceil(min);
//     max = Math.floor(max);
//     return Math.floor(Math.random() * (max - min)) + min; //不含最大值，含最小值
// }

function surroundHidden(id, hiddenId) {
    // console.log("surroundHidden");
    var blocks = document.getElementsByClassName("block");
    var thisX = blocks[id].mapId % 4;
    var thisY = Math.floor(blocks[id].mapId / 4);
    var hiddenX = blocks[hiddenId].mapId % 4;
    var hiddenY = Math.floor(blocks[hiddenId].mapId / 4);
    return (Math.abs(thisX - hiddenX) == 1 && thisY == hiddenY) ||
           (Math.abs(thisY - hiddenY) == 1 && thisX == hiddenX);
}

function randomSelect(gameMap, hidden) {
    var blocks = document.getElementsByClassName("block");
    // var id = getRandomInt(0, blocks.length);
    blocks[gameMap.pos[gameMap.pos.length - 1]].style.visibility = "hidden";
    hidden.id = gameMap.pos[gameMap.pos.length - 1];
}

function newGameMap(num) {
    var arr = new Array();
    for (var i = 0; i < num; i++) arr[i] = i;
    return arr;
}

function start(hidden, gameMap, blockSize, borderSize, topPx) {
    var btn = document.getElementById("restart");
    btn.addEventListener("click", function(event) {
        var blocks = document.getElementsByClassName("block");
        btn.innerText = "重新开始";
        gameMap.win = false;
        Array.from(blocks).forEach(function(block) {
            block.style.visibility = "visible";
        });
        gameMap.pos.shuffle();
        randomSelect(gameMap, hidden);
        while(solvability(gameMap.pos, 4) != true) {
            Array.from(blocks).forEach(function(block) {
                block.style.visibility = "visible";
            });
            gameMap.pos.shuffle();
            randomSelect(gameMap, hidden);
            }
        for (var i = 0; i < gameMap.pos.length; i++) {
            blocks[gameMap.pos[i]].mapId = i;
            blocks[gameMap.pos[i]].style.left = Math.floor(i / 4) * (blockSize + borderSize) + topPx + "px";
            blocks[gameMap.pos[i]].style.top = i % 4 * (blockSize + borderSize) + topPx + "px";
        }
    })
}


function main() {
    var gameMap = {pos:newGameMap(16), win:true};
    var hidden = {id:0};
    var blockSize = 87;
    var borderSize = 2;
    var topPx = 5.5;

    initial(gameMap, hidden, blockSize, borderSize, topPx);
    start(hidden, gameMap, blockSize, borderSize, topPx);
}

main();
