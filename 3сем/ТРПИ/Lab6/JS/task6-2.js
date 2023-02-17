let products = new Array();


// Разработайте класс Product, который позволяет добавлять (удалять, изменять) товар в каталог интернет-магазина. 
class Product{

    // Класс Product должен позволять:
    // - добавлять товар на страницу;
    // - удалять конкретный товар (например, по коду);
    // - устанавливать изображение товара (ссылку на изображение можно передавать в качестве параметры метода);
    // - устанавливать название товара;
    // - устанавливать стоимость товара;
    

    constructor(id, price, name, img, background){
        this.id = id;   
        this.price = price;
        this.name = name;
        this.img = img;
        this.background = background;
        products.push(this);
    }

    addOnPage(){
        // Стили для блока с товарами
        let div = document.createElement('div'); // создаем div
        div.className = "blockInfo";
        div.style.width = '250px';
        div.style.height = '350px';
        div.style.textAlign = 'center';
        div.style.background = this.background; 
        allProducts.append(div); // добавляем div в блок allProducts (метод append добавляет элемент в конец блока)
        allProducts.style.width = '100%';
        allProducts.style.display = 'flex';
        allProducts.style.flexWrap = 'wrap'; // делаем перенос элементов в блоке allProducts

        // Стили для изображения
        let img = document.createElement('img');
        img.src = this.img;
        img.style.width = '200px';
        img.style.height = '200px';
        div.prepend(img); // добавляем img в начало блока div (метод prepend добавляет элемент в начало блока)

        // Стили для текста под изображением
        let p = document.createElement('p');
        p.innerHTML = this.name;
        p.style.fontSize = '20px';
        p.style.fontWeight = 'bold';
        div.append(p); // добавляем p в конец блока div

        // Стили для текста с ценой
        let p2 = p.cloneNode(true); // клонируем p 
        p2.innerHTML = this.price + " $";
        p2.style.fontSize = '12px'; 
        div.append(p2); // добавляем p2 в конец блока div 
        let button = new Button(150, 75, 'blue','Buy now'); 
        div.append(button.addButton());  // добавляем кнопку в конец блока div 
        
    }

    delete(id){
        let massive = document.getElementsByClassName('blockInfo'); // получаем массив с блоками с товарами
        
        for(let x = 0; x < massive.length; x++){
            if((x+1) == id){
                massive[x].remove();
            }
        }

        let size = Object.getOwnPropertyNames(this); // получаем массив с названиями свойств объекта
        for(let i = 0; i < size.length; i++){
            delete this[size[i]];
        }
    }
}

class Button{

    // Для создания кнопок разработайте класс Button, который позволяет:
    // - создать, удалить кнопку;
    // - устанавливать размеры кнопки;
    // - устанавливать фон кнопки;
    // - устанавливать текст кнопки.


    constructor(width, height, background, text){
        this.width = width;
        this.height = height;
        this.text = text;
        this.background = background;
    }

    addButton(){
        let button = document.createElement('button');
        button.innerHTML = this.text;
        button.style.width = this.width;
        button.style.height = this.height;
        button.style.background = this.background;
        button.style.color = 'white';
        button.style.border = '5px solid blue';
        button.style.borderRadius = '5px';
        return button;
    }

    deleteButton(){
        let button = document.getElementsByTagName('button');
        button.remove();
    }

    setWidth(width){
        this.width = width;
    }

    setHeight(height){
        this.height = height;
    }

    setBackground(background){
        this.background = background;
    }

    setText(text){
        this.text = text;
    }
}

// После того как все товары добавлены на страницу, найдите все нечетные товары и задайте им серый фон.
function backgroundOdd(){
    let massive = document.getElementsByClassName('blockInfo');

    for(let i = 0 ; i < massive.length; i++){
        if((i+1) % 2 ==1 || (i+1) == 1 || (i+1) == 0){
            massive[i].style.background = 'gray';
        }
    }
}
let cartButton = new Button(150, 75, 'blue','Cart');
document.body.prepend(cartButton.addButton());

let first = new Product(1, 10000,'MacBook Pro 11', "Notebook.jpg", 'white');
first.addOnPage();

let second = new Product(2, 15000,'MacBook Pro 12', "Notebook.jpg", 'white');
second.addOnPage();

let third = new Product(3, 20000,'MacBook Pro 13', "Notebook.jpg", 'white');
third.addOnPage();

let fourth = new Product(4, 25000,'MacBook Pro 14', "Notebook.jpg", 'white');
fourth.addOnPage();

let fiveth = new Product(5, 30000,'MacBook Pro 15', "Notebook.jpg", 'white');
fiveth.addOnPage();

let sixth = new Product(6, 35000,'MacBook Pro 16', "Notebook.jpg", 'white');
sixth.addOnPage();

backgroundOdd();
sixth.delete(6);