let num = 6070809;
let count = 0;
let temp = num, rem;
while (temp > 0) {
    rem = temp % 10;
    if (rem === 0) {
        count++;
    }
    temp = parseInt(temp / 10);
}
console.log("the no. of zero:", count);



