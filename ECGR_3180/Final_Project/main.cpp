//Min Chang
//Github: Minyc510
#include "Graph.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string edgeString(tuple<string, string, int>); //Useful for print edges
void DijktrasTest(Graph G);
void PrimsTest(Graph G);

int main(){
  vector<string> nodes = {"A", "B", "C", "D"};
  Graph G;
  G.addNode(1.12314, "A");
  G.addNode(-7.3412, "B");
  G.addNode(420, "C");
  G.addNode(-12423, "D");

  G.addEdge("A","B", 1);
  G.addEdge("B","C", -714234.322323);
  G.addEdge("C","D", 313412341234123);
  G.addEdge("D","A", -3);

  G.saveGraph("Yee");
  Graph F(string("Yee.txt"));

  Graph H;
  H.addNode(123, "A");
  H.addNode(-513, "B");
  H.addNode(-690, "C");
  H.addNode(12319, "D");

  H.addEdge("A","B", 1720);
  H.addEdge("B","C", -7486);
  H.addEdge("C","D", -6457);
  H.addEdge("D","A", 7421);

  Graph N;

  cout << G.getInfo();
  cout << F.getInfo();
  cout << H.getInfo();
  cout << N.getInfo();

  cout << "\n------------------------------------" << endl;
  cout << "Done." << endl;
  cout << "------------------------------------" << endl;

  // Dijkstra Test Case
  vector<string> path = G.Dijktras("B", "D");
  cout << "Dijkstra Test Cases" << endl;
  for(const auto& node : path){
    cout << node << endl;  
  }
  cout << endl << "Done." << endl;

  path = N.Dijktras("A", "C");
  for(const auto& node : path){
    cout << node << endl;  
  }
  cout << endl << "Done." << endl;

  path = H.Dijktras("C", "A");
  for(const auto& node : path){
    cout << node << endl;  
  }
  cout << endl << "Done." << endl;

  cout << "\n------------------------------------" << endl;
  cout << "Done." << endl;
  cout << "------------------------------------" << endl;

  // Prims Test Case
  Graph test;
  cout << "Prims Test Cases" << endl;
  cout << "Test for Graph G";
  test = G.Prims();
  cout << test.getInfo() << endl;

  cout << "Test for Graph H";
  test = H.Prims();
  cout << test.getInfo() << endl;

  cout << "\n------------------------------------" << endl;
  cout << "Done." << endl;
  cout << "------------------------------------" << endl;

  // Kruksal Test Case
  cout << "Kruksal Test Cases" << endl;
  cout << "Test for Graph G";
  test = G.Kruskals();
  cout << test.getInfo() << endl;

  cout << "Test for Graph H";
  test = H.Kruskals();
  cout << test.getInfo() << endl;

  cout << "Test for Graph N";
  test = N.Kruskals();
  cout << test.getInfo() << endl;

  cout << "\n------------------------------------" << endl;
  cout << "Done." << endl;
  cout << "------------------------------------" << endl;
}

string edgeString(tuple<string, string, int> edge) {
  string str = get<0>(edge) + get<1>(edge) + to_string(get<2>(edge));
  return str;
}