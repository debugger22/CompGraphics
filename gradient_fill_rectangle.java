/**
* This is not a JAVA program. Use this code in processing framework.
*/


import javax.swing.JOptionPane;

int width = 500;
int height = 500;

int grid_lines = 20;  // Higher number slows recursion calls which results in internal crash

int sep_x = width/grid_lines;  // X spacing
int sep_y = height/grid_lines;  // Y spacing

int x1, y1; // Rectangle top left corner
int rect_width, rect_height;
int x;  // Input point coordinates
int y;

int deltaX = 1;  // Delta for change in Red

int [][] points;  // Array to store points
int counter = 0;

int last_text_pos = 0;


void setup(){
  size(width, height);
  background(0);

  // Taking input for the rectangle
  String str = JOptionPane.showInputDialog("Enter X1 Coordinate within 0 and " + String.valueOf(grid_lines));
  x1 = Integer.parseInt(str)*sep_x;

  str = JOptionPane.showInputDialog("Enter Y1 Coordinate within 0 and " + String.valueOf(grid_lines));
  y1 = Integer.parseInt(str)*sep_y;

  str = JOptionPane.showInputDialog("Enter rectangle width: ");
  rect_width = Integer.parseInt(str)*sep_x;

  str = JOptionPane.showInputDialog("Enter rectangle height: ");
  rect_height = Integer.parseInt(str)*sep_y;

  points = new int[(rect_width)*(rect_height)][2];  // Initializing points array based on input rectangle size

  // Taking input for the point
  str = JOptionPane.showInputDialog("Enter X Coordinate: ");
  x = Integer.parseInt(str)*sep_x;
  str = JOptionPane.showInputDialog("Enter Y Coordinate: ");
  y = Integer.parseInt(str)*sep_y;
  stroke(80);
  strokeWeight(1);
  drawGrids();  // Drawing grids

  stroke(255, 255, 255);
  noFill();
  strokeWeight(3);
  rect(x1, y1, rect_width, rect_height);  // Drawing rectangle
  strokeWeight(1);
  boolean is_inside = isInside(x, y, true);
  if(is_inside){
    crawl(x, y, 255);
  }
}


void draw(){

}


/**
* This function crawls the rectangle recursively and covers each cell
*/
void crawl(int x, int y, int red){
  boolean colored = colorPoint(x, y, red);
  if(colored && counter < (rect_width/sep_x)*(rect_height/sep_y)){
    // Storing colored point in the array
    points[counter][0] = x;
    points[counter][1] = y;
    counter++;
    int newRed = 255 - counter*deltaX;  // Color change function
    colored = colorPoint(x, y - sep_y, newRed);
    if(colored && !isColored(x, y - sep_y)) crawl(x, y - sep_y, newRed);  // Covering top side
    colored = colorPoint(x + sep_x, y, newRed);
    if(colored && !isColored(x + sep_x, y)) crawl(x + sep_x, y, newRed);  // Covering right side
    colored = colorPoint(x, y + sep_y, newRed);
    if(colored && !isColored(x, y + sep_y)) crawl(x, y + sep_y, newRed);  // Covering bottom side
    colored = colorPoint(x - sep_x, y, newRed);
    if(colored && !isColored(x - sep_x, y)) crawl(x - sep_x, y, newRed);  // Covering left side

    // Logging vertices
    System.out.println("("+String.valueOf(x/sep_x)+", "+String.valueOf(y/sep_y)+")");
  }
  return;
}


/**
* This function checks whether the point given has already been colored or not
*/
boolean isColored(int x, int y){
  for(int i=0; i<rect_width*rect_height; i++){
    if(points[i][0] == x && points[i][1] == y){
      return true;
    }
  }
  return false;
}


/**
* This function draws the grid
*/
void drawGrids(){
  for(int i=0; i<100; i++){
    line(i*sep_x, 0, i*sep_x, height);
  }

  for(int i=0; i<100; i++){
    line(0, i*sep_y, width, i*sep_y);
  }
}


/**
* This function checks whether the given point is in the bounds of the rectangle
*/
boolean isInside(int xl, int yl, boolean exit){
  if(xl >= x1 && xl < x1 + rect_width && yl >= y1 && yl < y1 + rect_height){
    return true;
  }
  if(exit){
    System.out.println("Point is outside the rectangle");
    exit();
  }
  return false;
}


/**
* This function colors a given point if it is withing the rectangle bounds
*/
boolean colorPoint(int xl, int yl, int red){
  if(isInside(xl, yl, false)){
    fill(red, 0, 0);
    stroke(red, 0, 0);
    rect(xl, yl, sep_x, sep_y);
    return true;
  }else{
    return false;
  }
}
