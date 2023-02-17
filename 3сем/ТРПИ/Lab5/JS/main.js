// 1. Хранилище всего имеющегося товара в интернет-магазине представляет собой объект products.  
// Весь товар разделен на категории, одна из них «Обувь», которая в свою очередь делится на виды «Ботинки», «Кроссовки», «Сандалии». 
// О каждой паре обуви хранится следующая информация: уникальный номер товара, размер обуви, цвет, цена. 

let Products = {
    shoes: {
        boots: {
            id: 1,
            size: 40,
            color: 'black',
            price: 1000

        },
        sneakers: {
            id: 2,
            size: 41,
            color: 'red',
            price: 8000

        },
        sandals: {
            id: 3,
            size: 42,
            color: 'white',
            price: 5500
        }
    }
}


// 2. Реализуйте итератор для объекта products для доступа к каждому товару.
Products[Symbol.iterator] = function() {
    let current = Products.shoes.boots.size; // текущее значение
    let last = Products.shoes.sandals.size; // последнее значение
    
    return { // метод должен вернуть объект с методом next()
        next() { // next() должен вернуть объект с двумя свойствами: done и value
            if (current <= last) {
                return { done: false, value: current++ }; 
            } else {
                return { done: true };
            }
        }
    };
};

for (let value of Products) { 
    console.log(value); 
}

// 3. Реализуйте фильтр обуви по цене в заданном диапазоне, по заданному размеру, по заданному цвету. 
// Выведите номера товаров, соответствующих заданному условию (фильтру).

let choice = 1;
while (choice != 0) {
    choice = prompt('Выберите действие: \n 1 - фильтр по цене \n 2 - фильтр по размеру \n 3 - фильтр по цвету \n 0 - выход');

    switch (choice) {
        case '1':
            let minPrice = prompt('Введите минимальную цену');
            let maxPrice = prompt('Введите максимальную цену');
            for (let key in Products.shoes) {
                if (Products.shoes[key].price >= minPrice && Products.shoes[key].price <= maxPrice) {
                    console.log(Products.shoes[key].id);
                }
            }
            break;
        case '2':
            let size = prompt('Введите размер');
            for (let key in Products.shoes) {
                if (Products.shoes[key].size == size) {
                    console.log(Products.shoes[key].id);
                }
            }
            break;
        case '3':
            let color = prompt('Введите цвет');
            for (let key in Products.shoes) {
                if (Products.shoes[key].color == color) {
                    console.log(Products.shoes[key].id);
                }
            }
            break;
        case '0':
            break;
        default:
            alert('Неверный ввод');
    }
}


// 4. Каждый товар (пара обуви) из предыдущей задачи представляет собой однотипные объекты. 
// Учитывая это, создайте объект товара с помощью new, 
// при этом свойства «id», «цвет» и «размер» должны быть доступны только для чтения, 
// свойство «id» не может быть удалено. 

let boots2 = new Object();

Object.defineProperty(boots2, 'id', {
    value: 4,
    writable: false,
    configurable: false, // нельзя удалить
});
Object.defineProperty(boots2, 'size', {
    value: 43,
    writable: false,
});
Object.defineProperty(boots2, 'color', {
    value: 'blue',
    writable: false,
});
Object.defineProperty(boots2, 'price', {
    value: 10000,
    writable: false,
});

console.log(boots2);
console.log(boots2.id);
delete boots2.id;
console.log(boots2.id);


// 5. Добавьте в описание товара новые свойства: «скидка» и «конечная стоимость» (стоимость с учетом скидки). 
// Добавьте геттер и сеттер для свойства «конечная стоимость», учитывая то, 
// что свойства «скидка» и «конечная стоимость» взаимозависимые.

Object.defineProperty(boots2, 'discount', {
    value: 10,
    writable: false,
});
Object.defineProperty(boots2, 'finalPrice', {
    get: function() {
        return this.price - this.price * this.discount / 100;
    },
    set: function(value) {
        this.discount = (this.price - value) / this.price * 100;
    }
});

console.log(boots2);
console.log(boots2.finalPrice);