#include <Arduino.h>
#include <Streaming.h>
#include <Array.h>
#include <IndexedContainer.h>


const long BAUD = 115200;

const int ELEMENT_COUNT_MAX = 7;
typedef IndexedContainer<uint32_t,ELEMENT_COUNT_MAX> Elements;
const size_t DELAY = 500;

bool removed = false;

void printIndexedContainer(Elements ic)
{
  Serial << "[";
  for (int i=0; i<ELEMENT_COUNT_MAX; i++)
  {
    if (i != 0)
    {
      Serial << ",";
    }
    if (ic.indexHasValue(i))
    {
      Serial << ic[i];
    }
    else
    {
      Serial << "X";
    }
  }
  Serial << "] <- All elements" << endl;
  delay(DELAY);
  Serial << "[";
  int i = 0;
  for (uint32_t element : ic)
  {
    if (i++ != 0)
    {
      Serial << ",";
    }
    Serial << element;
  }
  Serial << "] <- Elements with values" << endl;
  delay(DELAY);
}

void removeFromContainer(Elements & ic, int index)
{
  bool removed = ic.remove(index);
  Serial << "indexed_container.remove(" << index << ") :" << endl;
  if (removed)
  {
    Serial << "removed = true\n";
  }
  else
  {
    Serial << "removed = false\n";
  }
}

void setup()
{
  Serial.begin(BAUD);
  while (!Serial)
  {
    // wait for serial port to connect.
  }
}


void loop()
{
  Serial << "ELEMENT_COUNT_MAX :" << endl;
  Serial << ELEMENT_COUNT_MAX << endl;

  Elements indexed_container;
  Serial << "initial indexed_container :" << endl;
  printIndexedContainer(indexed_container);

  int index = indexed_container.add(1234);
  Serial << "indexed_container.add(1234) :" << endl;
  Serial << "index = " << index << "\n";
  printIndexedContainer(indexed_container);

  index = indexed_container.add(5678);
  Serial << "indexed_container.add(5678) :" << endl;
  Serial << "index = " << index << "\n";
  printIndexedContainer(indexed_container);

  index = indexed_container.add(90);
  Serial << "indexed_container.add(90) :" << endl;
  Serial << "index = " << index << "\n";
  printIndexedContainer(indexed_container);

  index = indexed_container.add(4321);
  Serial << "indexed_container.add(4321) :" << endl;
  Serial << "index = " << index << "\n";
  printIndexedContainer(indexed_container);

  index = 2;
  removeFromContainer(indexed_container,index);
  printIndexedContainer(indexed_container);

  index = indexed_container.add(3456);
  Serial << "indexed_container.add(3456) :" << endl;
  Serial << "index = " << index << "\n";
  printIndexedContainer(indexed_container);

  index = indexed_container.add(8765);
  Serial << "indexed_container.add(8765) :" << endl;
  Serial << "index = " << index << "\n";
  printIndexedContainer(indexed_container);

  index = indexed_container.add(77);
  Serial << "indexed_container.add(77) :" << endl;
  Serial << "index = " << index << "\n";
  printIndexedContainer(indexed_container);

  index = indexed_container.add(14);
  Serial << "indexed_container.add(14) :" << endl;
  Serial << "index = " << index << "\n";
  printIndexedContainer(indexed_container);

  index = 3;
  removeFromContainer(indexed_container,index);
  printIndexedContainer(indexed_container);

  index = 4;
  removeFromContainer(indexed_container,index);
  printIndexedContainer(indexed_container);

  index = -1;
  removeFromContainer(indexed_container,index);
  printIndexedContainer(indexed_container);

  index = 0;
  removeFromContainer(indexed_container,index);
  printIndexedContainer(indexed_container);

  index = 1;
  removeFromContainer(indexed_container,index);
  printIndexedContainer(indexed_container);

  index = 6;
  removeFromContainer(indexed_container,index);
  printIndexedContainer(indexed_container);

  index = 5;
  removeFromContainer(indexed_container,index);
  printIndexedContainer(indexed_container);

  index = 5;
  removeFromContainer(indexed_container,index);
  printIndexedContainer(indexed_container);

  index = 2;
  removeFromContainer(indexed_container,index);
  printIndexedContainer(indexed_container);

  index = indexed_container.add(99);
  Serial << "indexed_container.add(99) :" << endl;
  Serial << "index = " << index << "\n";
  printIndexedContainer(indexed_container);

  indexed_container.clear();
  Serial << "indexed_container.clear() :" << endl;
  printIndexedContainer(indexed_container);
}
