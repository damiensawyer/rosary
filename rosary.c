/* rosary.c — gcc rosary.c -o rosary && ./rosary [0-4]
   0 Joyful 1 Luminous 2 Sorrowful 3 Glorious 4 all; default: today's */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
char*P[]={"In the name of the Father, and of the Son, and of the Holy Spirit. Amen.",
"I believe in God, the Father almighty, Creator of heaven and earth, and in Jesus Christ, his only Son, our Lord, who was conceived by the Holy Spirit, born of the Virgin Mary, suffered under Pontius Pilate, was crucified, died and was buried; he descended into hell; on the third day he rose again from the dead; he ascended into heaven, and is seated at the right hand of God the Father almighty; from there he will come to judge the living and the dead. I believe in the Holy Spirit, the holy catholic Church, the communion of saints, the forgiveness of sins, the resurrection of the body, and life everlasting. Amen.",
"Our Father, who art in heaven, hallowed be thy name; thy kingdom come, thy will be done on earth as it is in heaven. Give us this day our daily bread, and forgive us our trespasses, as we forgive those who trespass against us; and lead us not into temptation, but deliver us from evil. Amen.",
"Hail Mary, full of grace, the Lord is with thee. Blessed art thou among women, and blessed is the fruit of thy womb, Jesus. Holy Mary, Mother of God, pray for us sinners, now and at the hour of our death. Amen.",
"Glory be to the Father, and to the Son, and to the Holy Spirit, as it was in the beginning, is now, and ever shall be, world without end. Amen.",
"O my Jesus, forgive us our sins, save us from the fires of hell, lead all souls to heaven, especially those in most need of thy mercy.",
"Hail, Holy Queen, Mother of Mercy, our life, our sweetness and our hope. To thee do we cry, poor banished children of Eve. To thee do we send up our sighs, mourning and weeping in this valley of tears. Turn then, most gracious advocate, thine eyes of mercy toward us, and after this our exile show unto us the blessed fruit of thy womb, Jesus. O clement, O loving, O sweet Virgin Mary. Pray for us, O holy Mother of God, that we may be made worthy of the promises of Christ.",
"Let us pray. O God, whose only begotten Son, by his life, death, and resurrection, has purchased for us the rewards of eternal life, grant, we beseech thee, that while meditating on these mysteries of the most holy Rosary of the Blessed Virgin Mary, we may imitate what they contain and obtain what they promise, through the same Christ our Lord. Amen."},
*S[]={"Joyful","Luminous","Sorrowful","Glorious"},*M[4][5]={
{"The Annunciation","The Visitation","The Nativity","The Presentation in the Temple","The Finding in the Temple"},
{"The Baptism of the Lord","The Wedding at Cana","The Proclamation of the Kingdom","The Transfiguration","The Institution of the Eucharist"},
{"The Agony in the Garden","The Scourging at the Pillar","The Crowning with Thorns","The Carrying of the Cross","The Crucifixion"},
{"The Resurrection","The Ascension","The Descent of the Holy Spirit","The Assumption","The Coronation of Mary"}};
int s;
void r(int n,void(*f)(int)){if(n)r(n-1,f),f(n);}
void p(int i){printf("%s\n\n",P[i]);}
void h(int n){printf("%2d. %s\n",n,P[3]);}
void d(int n){printf("\n=== %s Mystery %d: %s ===\n\n",S[s],n,M[s][n-1]);p(2);r(10,h);puts("");p(4);p(5);}
void g(int n){s=n-1;r(5,d);}
int main(int c,char**v){time_t t=time(0);int a=c>1?atoi(v[1]):"3023120"[localtime(&t)->tm_wday]-48;
p(0);p(1);p(2);r(3,h);puts("");p(4);a>3?r(4,g):(s=a,r(5,d));p(6);p(7);p(0);}
