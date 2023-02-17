let lettersInAlphabet = 26;
let numbers = 10;
let possibleLetters = 5;
let possibleNumbers = 3;
let averageTime = 3; // seconds
let rightPassword = Math.pow(lettersInAlphabet, possibleLetters) * Math.pow(numbers, possibleNumbers);

let timetoCrack = rightPassword * averageTime; 

let timetoCrackInMinutes = timetoCrack / 60; 
timetoCrack = timetoCrack % 60;

let timetoCrackInHours = timetoCrackInMinutes / 60;
timetoCrackInMinutes = timetoCrackInMinutes % 60;

let timetoCrackInDays = timetoCrackInHours / 24; 
timetoCrackInHours = timetoCrackInHours % 24;

let timetoCrackInYears = timetoCrackInDays / 365; 
timetoCrackInDays = timetoCrackInDays % 365;

console.log(`${timetoCrackInYears} лет, ${timetoCrackInDays} дней(дня), ${timetoCrackInHours} часов, 
${timetoCrackInMinutes} минут ${timetoCrack} секунды(секунд)`);

// Если округлить каждое число
console.log(`${Math.round(timetoCrackInYears)} лет, ${Math.round(timetoCrackInDays)} дней(дня),
${Math.round(timetoCrackInHours)} часов, ${Math.round(timetoCrackInMinutes)} минут
${Math.round(timetoCrack)} секунды(секунд)`);

