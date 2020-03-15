const displayedImage = document.querySelector('.displayed-img');
const thumbBar = document.querySelector('.thumb-bar');

const btn = document.querySelector('button');
const overlay = document.querySelector('.overlay');

/* 遍历图片并添加至缩略图区 */

for (let i = 1; i <= 5; i++) {
    const newImage = document.createElement('img');
    let path = `./images/pic${i}.jpg`;
    newImage.setAttribute('src', path);
    newImage.addEventListener('click', function () {
        let src = this.getAttribute('src');
        displayedImage.setAttribute('src', src);
    });
    thumbBar.appendChild(newImage);
}


/* 编写 变亮/变暗 按钮 */

btn.addEventListener('click', function() {
    let btnClass = btn.getAttribute('class');
    overlay.style.backgroundColor = btnClass == 'dark' ? 'rgba(0,0,0,.5)' : 'rgba(0,0,0,0)';
    btn.textContent = btnClass == 'dark' ? '变亮' : '变暗';
    btn.setAttribute('class', btnClass == 'dark' ? 'light' : 'dark');    
});
