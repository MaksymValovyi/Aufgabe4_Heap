#include <iostream>
#include "Heap.h"

using namespace std;



int main(int argc, char const *argv[])
{
    Heap heap(10);

    // Testfall 1: Schrittweise Aufbauen eines Heaps durch wiederholtes Aufrufen von Push
    cout << endl << "Testfall 1: Schrittweise Aufbauen eines Heaps durch Push:" << endl;
    heap.push(10);
    heap.push(4);
    heap.push(15);
    heap.push(20);
    heap.push(0);
    heap.push(8);
    heap.printHeap();

    // Testfall 2: Übergabe eines Arrays mit Werten und daraus Erstellen eines Heaps
    int values[] = { 5, 2, 9, 1, 7, 6 };
    heap.buildHeap(values, 6);
    cout << endl << "Testfall 2: Aufbau eines Heaps aus einem Array:" << endl;
    heap.printHeap();

    // Testfall 3: Sortierte Ausgabe der Elemente durch wiederholtes Aufrufen von Pop
    cout << endl << "Testfall 3: Sortierte Ausgabe durch Pop:" << endl;
    while (heap.getSize() > 0) {
        cout << heap.pop() << " " << endl;
        heap.printHeap();
    }
    cout << endl;

    return 0;
}
