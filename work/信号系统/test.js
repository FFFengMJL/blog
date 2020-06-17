var a = 1;
function main() {
  console.log(a);
  if (a == 1) {
    var a = 2;
  } else {
    var a = 3;
  }
  console.log(a);
}

main();
console.log(a);
