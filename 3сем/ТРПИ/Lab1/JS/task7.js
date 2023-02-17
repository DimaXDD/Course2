function compare(a, b) {
    if (a > b) {
        return 1;
    } else if (a < b) {
        return -1;
    } 
    return 0;
}

console.log( compare("Привет", "привет") ); // -1
console.log( compare("Привет", "Пока") ); // 1
console.log( compare(45, "53") ); // -1
console.log( compare(false, 3) ); // -1
console.log( compare(true, "3") ); // -1
console.log( compare(3, "5мм") ); // 0
console.log( compare(null, undefined) ); // 0