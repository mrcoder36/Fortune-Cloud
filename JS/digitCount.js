let num = 1234;
let count = 0;
let temp = num,
	rem;

while (temp > 0) {
	rem = temp % 10;
	count++;
	temp = parseInt(temp / 10);
}
console.log("Number of digits:", count);
