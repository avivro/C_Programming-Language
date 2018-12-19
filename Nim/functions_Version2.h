
#ifndef FUNCTIONS_VERSION2_H_
#define FUNCTIONS_VERSION2_H_

void turnComputer();
void turnUser();
bool UserPacketChange(int PacketToChange,int change);
bool ProperInputPacketToChange(int PacketToChange);
int SumOf2();
bool Option1(); /* x 0 0 */
bool Option2(); /* x 1 0 */
bool Option3(); /* x 1 1 */
bool Option4(); /* 0 1 1 */
bool Option5(); /* x x y x>y */
bool Option6(); /* x x y x<y */
bool Option7(); /* 2 3 x | x>3 */
void PrintPackest();
bool GameOver();
void sort();

#endif /* FUNCTIONS_VERSION2_H_ */
