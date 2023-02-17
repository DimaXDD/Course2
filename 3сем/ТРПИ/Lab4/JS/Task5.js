function makeCounter() {
    let currentCount = 1;
    return function () {
        return currentCount++;
    };
}
let currentCount = 1;
function makeCounter1() {
    return function () {
        return currentCount++;
    };
}
alert(`
Имя первой функции ${makeCounter.name}
Имя второй функции ${makeCounter1.name}
`);