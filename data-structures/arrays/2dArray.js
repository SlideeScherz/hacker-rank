/*
 * Complete the 'hourglassSum' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY arr as parameter.
 */
function hourglassSum(arr) {
  var sum = 0;
  var row = 0;

  //every pass, increment the row by one
  for (let outerRow = 0; outerRow < 4; outerRow++) {
    //reset col to zero each restart
    var col = 0;

    //every passes, increment the column to start
    for (let outerCol = 0; outerCol < 4; outerCol++) {
      //reset array
      var hourGlass = [];

      //columns
      for (var y = row; y < row + 3; y++) {
        //rows
        for (var x = col; x < col + 3; x++) {
          //top
          if (y == row) {
            console.log(`Pushing Top: ${arr[y][x]} (y: ${y} x: ${x})`);
            hourGlass.push(arr[y][x]);
          }

          //middle row
          else if (y == row + 1 && x == col + 1) {
            console.log(`Pushing Mid: ${arr[y][x]} (y: ${y} x: ${x})`);
            hourGlass.push(arr[y][x]);
          }
          //bottom
          else if (y == row + 2) {
            console.log(`Pushing bottom: ${arr[y][x]} (y: ${y} x: ${x})`);
            hourGlass.push(arr[y][x]);
          }
        }
      }

      console.log(`Hourglass made! ${hourGlass}`);

      //calculate the sum of the hourclass
      let sumBuffer = 0;
      hourGlass.forEach((elem) => {
        sumBuffer += elem;
      });

      console.log(`Sum: ${sum} sumBuffer: ${sumBuffer}`);
      if (sumBuffer > sum) {
        console.log(`Swap!`);
        sum = sumBuffer;
      }

      //increment the column to move to next hourglass
      col++;
    }

    //after 4 columns have been passes, move to next row below
    row++;
  }

  return sum;
}

