const dart = document.querySelector('.dart');

let startX = -100; 
let startY = -100;

let x = startX; 
let y = startY;
let wasClicked = false;

dart.onmousedown = function(event) {
    if (wasClicked) {
        document.body.onmousemove = null;                             
        document.body.onclick = () => animate(x, y, startX, startY); 
        return;
    }
    dart.style.zIndex = '1000'; // разместить поверх остального содержимого    
                                        
    wasClicked = wasClicked ? false : true;                            

    document.body.onmousemove = function(event) {
        if (startX === -100 && startY === -100) {                      
            startX = event.clientX - 5;                              
            dart.style.left = `${startX}px`;                         
            startY = event.clientY - 20;
            dart.style.top = `${startY}px`;
            dart.style.cursor = "none";
            document.body.append(dart);
        }
        if (Math.abs(startX - event.clientX) < 100) {
            x = event.clientX - 5;
        }
        if (Math.abs(startY - event.clientY) < 100) { 
            y = event.clientY - 5;
        }
        dart.style.left = `${x}px`;
        dart.style.top = `${y}px`;
    };
};

function animate(x, y, startX, startY) {
    dart.style.backgroundColor = `#009900`;
    let dx = (startX - x);
    let dy = (startY - y);
    let tg = dy / dx;
    startX = dx < 0 ? startX - 3 * Math.abs(dx) : startX + 3 * Math.abs(dx);
    startY = dy < 0 ? startY - 3 * Math.abs(tg * dx) : startY + 3 * Math.abs(tg * dx);
    dart.style.left = `${startX}px`;
    dart.style.top = `${startY}px`;

    // ============================= Убрать если пойдут баги =============================
    if (startX > 690 && startX < 800 && startY > 75 && startY < 140) {
        let score = document.querySelector('.score__value');
        score.innerHTML = +score.innerHTML + 100;
    }
    else {
        let score = document.querySelector('.score__value');
        score.innerHTML = +score.innerHTML - 100;
    }
}