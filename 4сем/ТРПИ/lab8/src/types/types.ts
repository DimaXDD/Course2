import {truncate} from "fs";

export interface IProduct{
    category: string;
    price: string;
    stocked: boolean;
    name: string;
}

export type FilterableProductTablePropsType = {
    products: IProduct[]
}

export type ProductTableType = {
    products: IProduct[]
    state: StateType
}

export type StateType = {
    filterText: string,
    inStockOnly: boolean,
    onFilterTextChange : (text : string) => void,
    onInStockChange : (status : boolean) => void,
};
