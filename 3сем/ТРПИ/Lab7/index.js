const dart = document.querySelector('.dart');
let startX = -100;
let startY = -100;
let x = startX;
let y = startY;
let wasClicked = false;

dart.onmousedown = function(event) {
    if (wasClicked) {
        document.body.onmousemove = null;                              // Отключение движения стрелы
        document.body.onclick = () => animate(x, y, startX, startY); 
        return;
    }
    dart.style.zIndex = '1000';                                        // Повышение z-index стрелы
    wasClicked = wasClicked ? false : true;                            // Переключение состояния стрелы

    document.body.onmousemove = function(event) {
        if (startX === -100 && startY === -100) {                      // Первое нажатие
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
            dart.style.backgroundColor = `#${Math.abs(startY - event.clientY)}${100 - Math.abs(startY - event.clientY)}00`;
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
    // ============================= Для расчёта координат, для счёта =============================
    //alert(`x: ${x}, y:${y}, dx: ${dx}, dy: ${dy}, tg: ${tg}, startX: ${startX}, startY: ${startY}`);
    dart.style.left = `${startX}px`;
    dart.style.top = `${startY}px`;

    // ============================= Убрать если пойдут баги =============================
    if (startX > 700 && startX < 800 && startY > 65 && startY < 145) {
        // Добавление очков в счет score__value
        let score = document.querySelector('.score__value');
        score.innerHTML = +score.innerHTML + 100;
    }
    else {
        // Уменьшение очков в счет score__value
        let score = document.querySelector('.score__value');
        score.innerHTML = +score.innerHTML - 100;
    }
}