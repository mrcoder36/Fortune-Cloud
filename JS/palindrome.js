let n = 1341;
let rev = 0, rem;
let temp = n;
while (temp > 0) {
    rem = temp % 10;
    rev = rev * 10 + rem;
    temp = parseInt(temp / 10);
}

if (rev == n) {
    console.log("The number is palindrome");
} else {
    console.log("The number is not Palindrome");
}

