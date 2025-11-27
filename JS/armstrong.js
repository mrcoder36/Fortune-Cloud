let num = 371;
let temp = num;
let rem, sum = 0;
while (temp > 0) {
    rem = temp % 10;
    sum += rem * rem * rem;
    temp = parseInt(temp / 10);
}
if (sum === num) {
    console.log("Number is armstrong..");
    
} else {
    console.log("Not a armstrong..");
    
}