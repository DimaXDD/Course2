function makeCounter() {
    let currentCount = 1;

    return function() {  
        return currentCount++; 
    };
}

let counter = makeCounter();

alert( counter() ); // 1
alert( counter() ); // 2
alert( counter() ); // 3

let counter2 = makeCounter();
alert( counter2() ); // 1 (independent) 