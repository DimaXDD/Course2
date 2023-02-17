let someData = prompt("Введите некие данные");

if (isFinite(Number(someData)) && !someData.includes(".")) {
  console.log("Вы ввели число " + someData);
  let someNumber = Number(someData);
  let hexNumber = someNumber.toString(16).toUpperCase();
  console.log("Ваше число в шестнадцатеричной системе счисления: " + hexNumber);
} else if (isFinite(Number(someData)) && Number(someData) % 1 !== 0) {
  console.log("Вы ввели дробное число " + someData);
  let someNumber = Number(someData);
  console.log(`
        Набольшую сторону: ${Math.ceil(someNumber)}\n
        Наименьшую: ${Math.floor(someNumber)}\n
        Ближайшее целое: ${Math.round(someNumber)}\n
    `);
} else {
  console.log("Вы ввели строку " + someData);
  console.log(`
    Upper: ${someData.toUpperCase()}\n
    Lower: ${someData.toLowerCase()}\n
`);
}
