// Реализуйте функцию без параметров. 
// Вызовите ее с произвольным количеством аргументов. 
// Если вы передали не более 3-х аргументов, то функция должна 
// возвращать строку, состоящую из значений всех аргументов. 
// Если вы передали более 3-х, но не более 5-ти аргументов – то типы аргументов. 
// Если более 5-ти и не более 7-ми – то   количество аргументов. 
// Если более 7-ми – то сообщение о том, что количество аргументов очень большое.

console.log(func(1, 2, 3)); 
console.log(func('a', 'b', 'c')); 
console.log(func(1, 'a', true));
console.log(func(1, 2, 3, 4)); 
console.log(func(1, 'a', true, false)); 
console.log(func(1, 2, 3, 4, 5, 6)); 
console.log(func(1, 2, 3, 4, 5, 6, 7, 8)); 

function func(...args) {
    if (args.length <= 3) {
        return args.join('');
    } else if (args.length > 3 && args.length <= 5) {
        return args.map(arg => typeof arg);
    } else if (args.length > 5 && args.length <= 7) {
        return args.length;
    } else {
        return 'Количество аргументов очень большое';
    }
}