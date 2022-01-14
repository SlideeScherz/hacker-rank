/* Complete the 'sockMerchant' function below.
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER_ARRAY ar
 */
function sockMerchant(n, ar) {
  let pairs = 0;
  let matchesThisPass;
  let pairsDone = [];

  //outer. pass 9
  for (let i = 0; i < n; i++) {
    //for each inner pass, reset to 0
    matchesThisPass = 0;

    console.log(
      `Checking if already a pair: ${ar[i]} => ${pairsDone.includes(ar[i])}`
    );

    if (pairsDone.includes(ar[i])) {
      console.log("Skip");
    } else {
      //inner pass
      for (let x = 0; x < n; x++) {
        console.log(`Evaluating ar[${i}] and ar[${x}] => ${ar[i]}, ${ar[x]}`);

        if (i === x) {
          console.log("I and X were the same. Skip");
        } else if (ar[i] === ar[x]) {
          pairsDone.push(ar[i]);
          console.log(`MATCH. matchesthispass++. Before: ${matchesThisPass}`);
          matchesThisPass++;
          console.log(`MTP Now: ${matchesThisPass}`);
        } else {
          console.log(`Not a match`);
        }
      }

      if (matchesThisPass === 1) {
        //pass
        console.log(`Handling mathces ${matchesThisPass} Leaving as is`);
      }

      //if not one and even
      else if (matchesThisPass % 2 == 0) {
        console.log(`Handling mathces ${matchesThisPass}/2`);
        matchesThisPass /= 2;
      }

      //if not one and odd
      else{
        console.log(`Handling mathces ${matchesThisPass} + 1 then / 2`);
        matchesThisPass++;
        matchesThisPass/=2;
      }
    }

    //Update the matches this pass.
    pairs += matchesThisPass;

    console.log(`Done with elem. Matches: ${matchesThisPass} Pairs: ${pairs}`);
    console.log(" ");
  }

  console.log(`${pairs}`);
  document.getElementById("demo").innerHTML = `Pairs: ${pairs}`;

  //return pairs;
}

/*
//const ar = [1, 1, 3, 1, 2, 1, 3, 3, 3, 3];
const ar = [20, 4, 5, 5, 5, 6, 6, 4, 1, 4, 4, 3, 6, 6, 3, 6, 1, 4, 5, 5, 5];
const n = ar.length;

document.getElementById("ar").innerHTML = `ar: ${ar}`;
document.getElementById("n").innerHTML = `n: ${n}`;
document.getElementById("expected").innerHTML = `expected: ${9}`;


sockMerchant(n, ar);
*/