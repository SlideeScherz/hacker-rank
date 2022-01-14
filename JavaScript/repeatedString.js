/*
 * Complete the 'repeatedString' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. LONG_INTEGER n
 */

function repeatedString(s, n) {

  console.log(s);

  var res = 0;

  var sArr = [...s];
  var sArrbuffer = [];

  //get correct array size with repeated s
  while(sArrbuffer.length < n){
    for(let i in sArr){
      if(sArrbuffer.length === n){
        break;
      }
      else{
        sArrbuffer.push(sArr[i]);
      }   
    } 
  }

  //set data back to sArr
  sArr = sArrbuffer;

  console.log(sArr);

  //count occurances of 'a'
  for(let i in sArr){
    if(sArr[i] === 'a'){
      res++;
    }
  }

  console.log(res);
  
  return res;

}


const s = 'a'
const n = 10;

repeatedString(s, n);