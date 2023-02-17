var Product = /** @class */ (function () {
    function Product(ID, type, price, Size, color, Sale) {
        if (Sale === void 0) { Sale = 0; }
        this.sale = 0;
        this.id = ID;
        this.size = Size;
        this.color = color;
        this.sale = Sale;
        this.price = price;
        this.endPrice = (100 - Sale) * price / 100;
        this.type = type;
    }
    Object.defineProperty(Product.prototype, "Type", {
        get: function () {
            return this.type;
        },
        enumerable: false,
        configurable: true
    });
    Object.defineProperty(Product.prototype, "ID", {
        get: function () {
            return this.id;
        },
        enumerable: false,
        configurable: true
    });
    Object.defineProperty(Product.prototype, "Size", {
        get: function () {
            return this.size;
        },
        enumerable: false,
        configurable: true
    });
    Object.defineProperty(Product.prototype, "Color", {
        get: function () {
            return this.color;
        },
        enumerable: false,
        configurable: true
    });
    Object.defineProperty(Product.prototype, "Price", {
        get: function () {
            return this.endPrice;
        },
        set: function (v) {
            this.price = v;
            this.endPrice = (100 - this.sale) * this.price / 100;
        },
        enumerable: false,
        configurable: true
    });
    Product.prototype.toString = function () {
        return ("id: ".concat(this.id, "\n name: ").concat(this.type, " \n color: ").concat(this.color, " \n size: ").concat(this.size, "\n price: ").concat(this.endPrice));
    };
    return Product;
}());
var products = [
    new Product(1, "Кроссовки", 150, 42, "black"),
    new Product(2, "Ботинки", 200, 40, "black", 20),
    new Product(3, "Сандали", 50, 42, "white", 10)
];
var ProductIterator = /** @class */ (function () {
    function ProductIterator(products) {
        this.products = products;
        this.index = -1;
        this.products = products;
    }
    ProductIterator.prototype.next = function () {
        if (this.index < products.length - 1) {
            return { done: false, value: products[++this.index] };
        }
        else {
            return { done: true, value: null };
        }
    };
    return ProductIterator;
}());
var iterator = new ProductIterator(products);
var prod = iterator.next();
while (prod.done != true) {
    console.log(prod.value);
    prod = iterator.next();
}
//Задание_3
function filtreByPrice(priceFrom, priceTo) {
    console.log("\nFilter by price:");
    products.forEach(function (Element) {
        if (Element.price > priceFrom && Element.price < priceTo) {
            console.log(Element.toString());
        }
    });
}
function filtreByColor(color) {
    console.log('\nFilter by color: ');
    products.forEach(function (element) {
        if (element.color == color) {
            console.log(element.toString());
        }
    });
}
function filtreBySize(size) {
    console.log('\nFilter by size: ');
    products.forEach(function (element) {
        if (element.size == size) {
            console.log(element.toString());
        }
    });
}
filtreBySize(42);
filtreByColor("black");
filtreByPrice(40, 160);
