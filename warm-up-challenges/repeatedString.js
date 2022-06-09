/*
 * Complete the 'repeatedString' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. LONG_INTEGER n
 */

function repeatedString(s, n) {
  var arr = [...s];

  var size = s.length;
  var rem = n % size;
  var repeated = (n - rem) / size;

  //results
  var singlePass = 0;
  var extra = 0;

  //regular pass
  for (let i = 0; i < size; i++) {
    if (arr[i] == "a") {
      singlePass++;
    }
  }

  //account for extra
  for (let i = 0; i < rem; i++) {
    console.log("Doing extra");
    if (arr[i] === "a") {
      extra++;
    }
  }

  console.log(`SP: ${singlePass} Repeated: ${repeated} Extra: ${extra}`);

  var res = singlePass * repeated + extra;

  return res;
}

const s = "a";
const n = 10;

repeatedString(s, n);
