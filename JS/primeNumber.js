let num = 15;
let isPrime;
if (num <= 1) {
    console.log(n + "is not prime..");
} else {
    for (let i = 0; i < Math.sqrt(num); i++) {
        if (num % i === 0) {
            return false;
        }
    }
    return true;
}
if (isPrime) {
    console.log("Prime..");   
} else {
    console.log("not prime..");
}
let m  = Math.sqrt(num)
console.log(m);