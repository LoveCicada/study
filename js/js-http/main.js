
function add(){
    let sum = 0;
    for(let i = 0, j = arguments.length; i<j; ++i){
        sum += arguments[i];
    }
    return sum;
}

let sumTotal = add(1,2,3,4,5,6,7,8,9,10);
console.log(sumTotal);

function makeAdder(a){
    return function(b){
        return a + b;
    };
}

let x = makeAdder(5);
let y = x(7);
console.log(y);