#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Bonus
//遊戲人數可在遊戲開始前由使用者自行選擇             (達成)  
//可自行設計多個其他事件，並隨機發生一種事件-機會    (達成) 
//自訂其他恢復動做的條件-監獄                        (達成)  
//可自行設計多個其他事件，並隨機發生一種事件-命運    (達成) 
//自行設計其他特殊地點                               (達成)  
//若走到的是其他自行設計的特殊地點，則自行設計事件	 (達成) 
//自行處理淘汰玩家的土地                             (達成) 


void local(int m){ //位置 
	switch(m){
		case 0 : 
			printf("        起點");
			break;
		case 1 : 
			printf("魔法森林西部");
			break;
		case 2 : 
			printf("    巨樹森林");
			break;
		case 3 : 
			printf("魔法森林東部");
			break;
		case 4 : 
			printf("    暗黑森林");
			break;
		case 5 : 
			printf("    地下水路");
			break;
		case 6 : 
			printf("    瓦利城堡");
			break;
		case 7 : 
			printf("    貝馬山谷");
			break;
		case 8 : 
			printf("        機會");
			break;
		case 9 : 
			printf("      貝馬湖");
			break;
		case 10 : 
			printf("    採礦中心");
			break;
		case 11 : 
			printf("    夢境平原");
			break;
		case 12 : 
			printf("        監獄");
			break;
		case 13 : 
			printf("  厄泰拉核心");
			break;
		case 14 : 
			printf("奉獻神殿入口");
			break;
		case 15 : 
			printf("    奉獻祭壇");
			break;
		case 16 : 
			printf("第三居住地區");
			break;
		case 17 : 
			printf("  第一商業區");
			break;
		case 18 : 
			printf("    瑞安郊區");
			break;
		case 19 : 
			printf("    水之神殿");
			break;
		case 20 : 
			printf("        命運");
			break;
		case 21 : 
			printf("    大地縫隙");
			break;
		case 22 : 
			printf("天空中的岔路");
			break;
		case 23 : 
			printf("  天使居住所");
			break;
	}
}

int point(){       //骰骰子
	int r;
	srand(time(NULL));  
	r = rand()%6+1;
	return r;
}

int land(int m){   //土地價格設定 
	switch(m){
		case 0 : //起點
			return -1;
			break;
		case 1 : //魔法森林西部
			return 10000;
			break;
		case 2 : //巨樹森林
			return 50000;
			break;
		case 3 : //魔法森林東部
			return 10000;
			break;
		case 4 : //暗黑森林
			return 70000;
			break;
		case 5 : //地下水路
			return 80000;
			break;
		case 6 : //瓦利城堡
			return 100000;
			break;
		case 7 : //貝馬山谷
			return 120000;
			break;
		case 8 : //機會|
			return -1;
			break;
		case 9 : //貝馬湖
			return 150000;
			break;
		case 10 : //採礦中心
			return 150000;
			break;
		case 11 : //夢境平原
			return 180000;
			break;
		case 12 : //監獄
			return -1;
			break;
		case 13 : //厄泰拉核心
			return 200000;
			break;
		case 14 : //奉獻神殿入口
			return 250000;
			break;
		case 15 : //奉獻祭壇
			return -1;
			break;
		case 16 : //第三居住地區
			return 300000;
			break;
		case 17 : //第一商業區
			return 350000;
			break;
		case 18 : //瑞安郊區
			return 450000;
			break;
		case 19 : //水之神殿
			return 500000;
			break;
		case 20 : //命運
			return -1;
			break;
		case 21 : //大地縫隙
			return 700000;
			break;
		case 22 : //天空中的岔路
			return 1000000;
			break;
		case 23 : //天使居住所
			return 10000000;
			break;
	}
}

struct loda{       //土地資訊 
	int price;//土地價格 
	int level;
	int p; //所擁有者 P1=1,P2=2以此類推 
};

struct data{       //玩家屬性 
	int la;       //所在位置
	int money;    //錢 
	int x;  	  //監獄指數 
};

int main() {
	int p;//玩家人數
	char *move0[24]={"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "};
	char *move1[24]={"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "};
	char *move2[24]={"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "};
	char *move3[24]={"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "};
	char *move4[24]={"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "};
	char *move5[24]={"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "};
	char *life[6]={" 1"," 2"," 3"," 4"," 5"," 6"};
	do{
		printf("輸入遊玩的人數(4~6人) : ");                     //輸入玩家人數 
		 
		scanf("%d",&p);
	}while(p!=4&&p!=6&&p!=5);
	
	struct data player[p];
	struct loda infor[24];
	int i,j,y=0,out=0;  //迴圈,破產人數,跳出迴圈 
	int m,tmp1,tmp2;//存取骰子點數or隨機效果 ,暫存 
	char a; //輸入選項用 
	//int b;
	int r;         //隨機 
	srand(time(NULL));  
	
	for(i=0;i<p;i++){ 
		player[i].la=0;        //玩家位置初始化
		player[i].money=5000000;//玩家財產初始化
		player[i].x=0;         //玩家監獄指數初始化
	} 
	for(i=0;i<24;i++){
		infor[i].level=0;	   //土地等級初始化 
		infor[i].p=0;		   //土地擁有者初始化
		infor[i].price=land(i);//土地價格設定
	}			
		
	while(1){
		
		for(y=0,i=0;i<p;i++){//如果剩下一人就跳出迴圈 
			if(player[i].money<=0)
				y+=1;
			}
			if(y==p-1)
				goto end;
		for(i=0;i<p;i++){
			
			////////////顯示地圖設定 
			int l,m,n,o;//地圖中間P5P6的輸出結果 
			if(p==4){
				n=0;//P5財產 
				o=0;//P6財產
			}
			else if(p==5){
				n=player[p-1].money;
				o=0;
			}
			else{
				n=player[p-2].money;
				o=player[p-1].money;
			}
			////////////顯示地圖設定
			if(p==6){
				move0[(player[0].la)]=life[0];
				move1[(player[1].la)]=life[1];
				move2[(player[2].la)]=life[2];
				move3[(player[3].la)]=life[3];
				move4[(player[4].la)]=life[4];
				move5[(player[5].la)]=life[5];
			}
			else if(p==5){
				move0[(player[0].la)]=life[0];
				move1[(player[1].la)]=life[1];
				move2[(player[2].la)]=life[2];
				move3[(player[3].la)]=life[3];
				move4[(player[4].la)]=life[4];
			}
				else if(p==4){
				move0[(player[0].la)]=life[0];
				move1[(player[1].la)]=life[1];
				move2[(player[2].la)]=life[2];
				move3[(player[3].la)]=life[3];
			}
			system("cls");
		////插入地圖////
		if(1){
			printf("-------------------------------------------------------------------------------------------\n");
			printf("|         |   P %d   |   P %d   |         |   P %d   |   P %d   |   P %d   |   P %d   |         |\n",infor[13].p,infor[14].p,infor[16].p,infor[17].p,infor[18].p,infor[19].p);
			printf("|  監 獄  | 厄 泰 拉| 奉獻神殿| 奉獻祭壇|第三居住 |  第一   | 瑞安郊區|水之神殿 |   命運  |\n");
			printf("|         |   核心  |   入口  |         |  地區   | 商業區  |         |         |         |\n");
			printf("|         |         |         |         |         |         |         |         |         |\n");
			printf("| %s%s%s  | %s%s%s  | %s%s%s  | %s%s%s  | %s%s%s  | %s%s%s  | %s%s%s  | %s%s%s  | %s%s%s  |\n",move0[12],move1[12],move2[12],move0[13],move1[13],move2[13],move0[14],move1[14],move2[14],move0[15],move1[15],move2[15],move0[16],move1[16],move2[16],move0[17],move1[17],move2[17],move0[18],move1[18],move2[18],move0[19],move1[19],move2[19],move0[20],move1[20],move2[20]);
			printf("| %s%s%s  | %s%s%s  | %s%s%s  | %s%s%s  | %s%s%s  | %s%s%s  | %s%s%s  | %s%s%s  | %s%s%s  |\n",move3[12],move4[12],move5[12],move3[13],move4[13],move5[13],move3[14],move4[14],move5[14],move3[15],move4[15],move5[15],move3[16],move4[16],move5[16],move3[17],move4[17],move5[17],move3[18],move4[18],move5[18],move3[19],move4[19],move5[19],move3[20],move4[20],move5[20]);
			printf("|         |  LV. %d  |  LV. %d  |         |  LV. %d  |  LV. %d  |  LV. %d  |  LV. %d  |         |\n",infor[13].level,infor[14].level,infor[16].level,infor[17].level,infor[18].level,infor[19].level);			
			printf("-------------------------------------------------------------------------------------------\n");
			printf("|   P %d   |                                                                     |   P %d   |\n",infor[11].p,infor[21].p);
			printf("| 夢境平原|         P1                                 P2                       | 大地縫隙|\n");
			printf("|         |        位置:");
			local(player[0].la);
			printf("                  位置:");
			local(player[1].la);
			printf("         |         |\n");
			printf("|         |        財產:%10d元                  財產:%10d元         |         |\n",player[0].money,player[1].money);
			printf("| %s%s%s  |                                                                     | %s%s%s  |\n",move0[11],move1[11],move2[11],move0[21],move1[21],move2[21]);
			printf("| %s%s%s  |                                                                     | %s%s%s  |\n",move3[11],move4[11],move5[11],move3[21],move4[21],move5[21]);
			printf("|  LV. %d  |                                                                     |  LV. %d  |\n",infor[11].level,infor[21].level);
			printf("-----------                                                                     -----------\n");
			printf("|   P %d   |                                                                     |   P %d   |\n",infor[10].p,infor[22].p);
			printf("| 採礦中心|         P3                                 P4                       |  天空中 |\n");
			printf("|         |        位置:");
			local(player[2].la);
			printf("                  位置:");
			local(player[3].la);
			printf("         |  的岔路 |\n");
			printf("|         |        財產:%10d元                  財產:%10d元         |         |\n",player[2].money,player[3].money);
			printf("| %s%s%s  |                                                                     | %s%s%s  |\n",move0[10],move1[10],move2[10],move0[22],move1[22],move2[22]);
			printf("| %s%s%s  |                                                                     | %s%s%s  |\n",move3[10],move4[10],move5[10],move3[22],move4[22],move5[22]);
			printf("|  LV. %d  |                                                                     |  LV. %d  |\n",infor[10].level,infor[22].level);
			printf("-----------                                                                     -----------\n");
			printf("|   P %d   |         P5                                 P6                       |   P %d   |\n",infor[9].p,infor[23].p);
			printf("|  貝馬胡 |        位置:");
			
			if(p==5)
				local(player[p-1].la);
			else if(p==6)
				local(player[p-2].la);
			else
				printf("          無");
			printf("                  位置:");
			if(p==6)
				local(player[p-1].la);
			else
				printf("          無");
			printf("         |   天使  |\n");
			printf("|         |        財產:%10d元                  財產:%10d元         |  居住所 |\n",n,o);
			printf("|         |                                                                     |         |\n");
			printf("| %s%s%s  |                                                                     | %s%s%s  |\n",move0[9],move1[9],move2[9],move0[23],move1[23],move2[23]);
			printf("| %s%s%s  |                                                                     | %s%s%s  |\n",move3[9],move4[9],move5[9],move3[23],move4[23],move5[23]);
			printf("|  LV. %d  |                                                                     |  LV. %d  |\n",infor[9].level,infor[23].level);
			printf("-------------------------------------------------------------------------------------------\n");
			printf("|         |   P %d   |   P %d   |   P %d   |   P %d   |   P %d   |   P %d   |   P %d   |         |\n",infor[7].p,infor[6].p,infor[5].p,infor[4].p,infor[3].p,infor[2].p,infor[1].p);
			printf("|  機 會  | 貝馬山谷| 瓦利城堡| 地下水路| 暗黑森林| 魔法森林| 巨樹森林|魔法森林 |   起點  |\n");
			printf("|         |         |         |         |         |   東部  |         |  西部   |         |\n");
			printf("|         |         |         |         |         |         |         |         |         |\n");
			printf("| %s%s%s  | %s%s%s  | %s%s%s  | %s%s%s  | %s%s%s  | %s%s%s  | %s%s%s  | %s%s%s  | %s%s%s  |\n",move0[8],move1[8],move2[8],move0[7],move1[7],move2[7],move0[6],move1[6],move2[6], move0[5],move1[5],move2[5],move0[4],move1[4],move2[4], move0[3],move1[3],move2[3],move0[2],move1[2],move2[2],move0[1],move1[1],move2[1], move0[0],move1[0],move2[0]);
			printf("| %s%s%s  | %s%s%s  | %s%s%s  | %s%s%s  | %s%s%s  | %s%s%s  | %s%s%s  | %s%s%s  | %s%s%s  |\n",move3[8],move4[8],move5[8],move3[7],move4[7],move5[7],move3[6],move4[6],move5[6], move3[5],move4[5],move5[5],move3[4],move4[4],move5[4], move3[3],move4[3],move5[3],move3[2],move4[2],move5[2],move3[1],move4[1],move5[1], move3[0],move4[0],move5[0]);
			printf("|         |  LV. %d  |  LV. %d  |  LV. %d  |  LV. %d  |  LV. %d  |  LV. %d  |  LV. %d  |         |\n",infor[7].level,infor[6].level,infor[5].level,infor[4].level,infor[3].level,infor[2].level,infor[1].level);
			printf("-------------------------------------------------------------------------------------------\n");
		}
			
			////跳過破產的回合////
			if(player[i].money<=0) 
				continue;
			////跳過破產的回合////
			
			 
			printf("玩家 : P%d\n",i+1);
			printf("玩家位置 : ");
			local(player[i].la);
			printf("\n");
			printf("目前財產 :%d\n",player[i].money);
			if(p==6){
				move0[(player[0].la)]="  ";
				move1[(player[1].la)]="  ";
				move2[(player[2].la)]="  ";
				move3[(player[3].la)]="  ";
				move4[(player[4].la)]="  ";
				move5[(player[5].la)]="  ";
			}
			else if(p==5){
				move0[(player[0].la)]="  ";
				move1[(player[1].la)]="  ";
				move2[(player[2].la)]="  ";
				move3[(player[3].la)]="  ";
				move4[(player[4].la)]="  ";
			}
				else if(p==4){
				move0[(player[0].la)]="  ";
				move1[(player[1].la)]="  ";
				move2[(player[2].la)]="  ";
				move3[(player[3].la)]="  ";
			}
			////行動////
			if(1) {
				if(player[i].x>0)
					goto prison;
				m=point();
				printf("你骰出了%d點,移動%d步\n",m,m);
				player[i].la=(player[i].la+m)%24;
				printf("你移動到了-> ");
				local(player[i].la);
				printf("\n");
				printf("\n地區資訊:\n");
				if(player[i].la==0||player[i].la==8||player[i].la==12||player[i].la==15||player[i].la==20)
					printf("該地區是特殊地點\n\n");
				else{
					if(infor[player[i].la].p!=0)
						printf("該地區所有人:P%d\n",infor[player[i].la].p);
					else
						printf("該地區所有人:無\n");
					printf("該地區等級:%d級\n\n",infor[player[i].la].level);
				}
			}
			
			if(player[i].la==0||player[i].la==8||player[i].la==12||player[i].la==15||player[i].la==20)
					goto sp;//sp:處理特殊地點的狀況
			else{//如果走到一般地點 
				if(infor[player[i].la].level==0){    //如果該地區沒人買，詢問要不要買土地 
					printf("該地區購買價格為%d元\n",infor[player[i].la].price);
					printf("此土地尚未購買，你要購買嗎(y/n)\n");
					if(infor[player[i].la].price>=player[i].money)
						printf("你:嗚嗚嗚~錢不夠買\n");
					else{
						scanf("%c",&a);
						printf("你的回答:");
						scanf("%c",&a);
						if(a=='y'||a=='Y'){
							player[i].money-=infor[player[i].la].price;
							printf("購買成功\\n");
							printf("目前財產 :%d\n",player[i].money);
							infor[player[i].la].level=1;//等級 
							infor[player[i].la].p=i+1;//所有者 
							printf("該地區等級升級為0->1級\n");
						}
						else if(a!='n'&&a!='N')
							printf("不要為難我好嗎?專題很難做,只好當作no\n");
					}
					goto sp;//sp:處理特殊地點的狀況
				}
				if(infor[player[i].la].level==1){   //如果該地區為1級
					if(infor[player[i].la].p==i+1){ //如果該地區是當前玩家的 
						printf("升級土地須花費%d元\n",infor[player[i].la].price*3);
						printf("你要升級你的土地嗎?(y/n)\n");
						if(infor[player[i].la].price*3>=player[i].money)
							printf("你:嗚嗚嗚~錢不夠買\n");
						else{
							scanf("%c",&a);
							printf("你的回答:");
							scanf("%c",&a);
							if(a=='y'||a=='Y'){
								player[i].money-=infor[player[i].la].price*3;
								printf("購買成功\\n");
								printf("目前財產 :%d\n",player[i].money);
								infor[player[i].la].level=2;//等級 
								printf("該地區等級升級為1->2級\n");
							}
							else if(a!='n'&&a!='N')
								printf("不要為難我好嗎?專題很難做,只好當作no\n");
						}
					}
					else{//如果不是該玩家的，續...
						printf("你目前站在P%d的土地上，付過路費給地主\n",infor[player[i].la].p);
						printf("過路費為%.0f元\n",infor[player[i].la].price*0.4);
						if(infor[player[i].la].price*0.4<player[i].money){//如果玩家可負擔 
							player[i].money-=infor[player[i].la].price*0.4;//付錢 
							player[infor[player[i].la].p-1].money+=infor[player[i].la].price*0.4;//收錢 
							printf("支付成功\\n");
							printf("目前財產 :%d\n",player[i].money);
						}
						else{
							printf("你已經破產了,幫你QQ\n");//地主獲得該玩家的剩餘財產 
							player[infor[player[i].la].p-1].money+=player[i].money;//收錢 
							player[i].money=0;
						}
					}
					goto sp; //sp:處理特殊地點的狀況
				}
				if(infor[player[i].la].level==2){   //如果該地區為2級
					if(infor[player[i].la].p==i+1){ //如果該地區是當前玩家的 
						printf("升級土地須花費%d元\n",infor[player[i].la].price*5);
						printf("你要升級你的土地嗎?(y/n)\n");
						if(infor[player[i].la].price*5>=player[i].money)
							printf("你:嗚嗚嗚~錢不夠買\n");
						else{
							printf("喔不這次我們會強迫你升級\n");
							if(1){
								player[i].money-=infor[player[i].la].price*5;
								printf("購買成功\\n");
								printf("目前財產 :%d\n",player[i].money);
								infor[player[i].la].level=3;//等級 
								printf("該地區等級升級為2->3級\n");
								printf("該地區已升級至最大\n");
							}
						}
					}
					else{//如果不是該玩家的，續...
						printf("你目前站在P%d的土地上，付過路費給地主\n",infor[player[i].la].p);
						printf("過路費為%.0f元\n",infor[player[i].la].price*1.2);
						if(infor[player[i].la].price*1.2<player[i].money){//如果玩家可負擔 
							player[i].money-=infor[player[i].la].price*1.2;//付錢 
							player[infor[player[i].la].p-1].money+=infor[player[i].la].price*1.2;//收錢 
							printf("支付成功\\n");
							printf("目前財產 :%d\n",player[i].money);
						}
						else{
							printf("你已經破產了,幫你QQ\n");//地主獲得該玩家的剩餘財產 
							player[infor[player[i].la].p-1].money+=player[i].money;//收錢 
							player[i].money=0;
						}
					}
					goto sp;//sp:處理特殊地點的狀況
				}
				if(infor[player[i].la].level==3){   //如果該地區為3級
					if(infor[player[i].la].p==i+1){ //如果該地區是當前玩家的
						printf("雖然該地區已經不能升級了\n");
						printf("但是你可以獲得10萬元\n");
						player[i].money+=100000;
						printf("目前財產 :%d\n",player[i].money);
					}
					else{//如果不是該玩家的，續...
						printf("你目前站在P%d的土地上，付過路費給地主\n",infor[player[i].la].p);
						printf("過路費為%d元\n",infor[player[i].la].price*2);
						if(infor[player[i].la].price*2<player[i].money){//如果玩家可負擔 
							player[i].money-=infor[player[i].la].price*2;//付錢 
							player[infor[player[i].la].p-1].money+=infor[player[i].la].price*2;//收錢 
							printf("支付成功\\n");
							printf("目前財產 :%d\n",player[i].money);
						}
						else{
							printf("你已經破產了,幫你QQ\n");//地主獲得該玩家的剩餘財產 
							player[infor[player[i].la].p-1].money+=player[i].money;//收錢 
							player[i].money=0;
						}
					}
				}
			}
			////行動//// 
			
			////特殊地區//// 
			sp: 
			if(player[i].la==0){                     //起點獲得獎勵 
				printf("回歸起點,獎金10000元\n");
				player[i].money+=10000;
				printf("目前財產 :%d\n",player[i].money);
			}
			else if(player[i].la==8){                //機會獲得獎勵 
				printf("你獲得了丟骰子拿獎金的機會，丟到3以上獲得獎金，丟到1會有隨機事件發生\n"); 
				m=point();
				printf("你擲出了%d點\n",m);
				if(m>=3){
					printf("恭喜中獎,獎金10000元\n");
					player[i].money+=10000;
					printf("目前財產 :%d\n",player[i].money);
				}
				else if(m==1){                       //隨機事件 
					m = rand()%10+1;
					if(m<3){
						if(player[i].x==0){
							printf("隨機事件:被發現在廁所打lol,被關進了監獄\n");
							player[i].la=12;
							player[i].x+=1;
							printf("玩家位置 : ");
							local(player[i].la);
							printf("\n\n");
							continue;
						}
					}
					else if(m==5||m==6){
						printf("隨機事件:熬夜趕報告，違反宿舍守則，罰1萬元\n");
						player[i].money-=10000;
						if(player[i].money<0)
							player[i].money=0;
						printf("目前財產 :%d\n",player[i].money);
					}
					else
						printf("隨機事件:甚麼也沒有發生\n");
				}
				else
					printf("真可惜下次再來\n");
			}
			else if(player[i].la==12){               //被關進監獄 
				prison:
				player[i].x+=1;
				if(	player[i].x==1){
					printf("你被關進了監獄,休息一回合\n\n\n");
					system("pause"); 
					continue;
				}
				else if(player[i].x>1){	
					printf("因為被關進監獄，丟到偶數時，下一回合才可以移動\n"); 
					m=point();
					printf("你擲出了%d點\n",m);
					if(m%2==0){
						player[i].x=0;
						printf("恭喜你出獄了!!\n");
					}
					else{
						printf("抱歉嘍，你要繼續被關\n");
						if(player[i].money>10000){   //自訂其他恢復動做的條件
							printf("但是你身上超過一萬元，你想用這些錢賄絡警察嗎(y/n):\n");
							scanf("%c",&a);//修正BUG ,這一行程式不會跑很奇怪 
							printf("你的回答:");
							scanf("%c",&a);
							if(a=='y'||a=='Y'){
								player[i].money-=10000;
								printf("目前財產 :%d\n",player[i].money);
								player[i].x=0;
								printf("恭喜你出獄了!!\n");
							}
							else if(a!='n'&&a!='N')
								printf("不要為難我好嗎?專題很難做,只好當作回答no\n");
						}
					}
				}
			}
			else if(player[i].la==20){               //命運大輪盤 
				printf("玩家的位置開始互換...\n");
				m=rand()%(p-1)+1;
				while(m--){                          //隨機互換，位置玩家位移m次
					tmp1=player[0].la;  
					tmp2=player[0].x;//如果換到監獄的話，監獄狀態也要交換 
					for(j=0;j<p;j++){   
						if(j==p-1){
							player[j].la=tmp1;
							player[j].x=tmp2;
						}
						else{
							player[j].la=player[j+1].la;
							player[j].x=player[j+1].x;
						}
					}
				}
				m=rand()%10;                         //隨機事件 
				if(m<=1){
					printf("突發事件:恭喜你因為幫老奶奶過馬路，得到了1萬元\n");
					player[i].money+=10000;
					printf("目前財產 :%d\n",player[i].money);
				}	
			}
			else if(player[i].la==15){               //新增特殊地點-奉獻祭壇 
				printf("你走到了奉獻祭壇，必須奉獻出你的財富的75%%，且把你傳回起點\n");
				player[i].money/=4;
				printf("目前財產 :%d\n",player[i].money);
				player[i].la=0;
				printf("玩家位置 : ");
				local(player[i].la);
			}
			////特殊地區end//// 
			
			if(player[i].money<=0){                   
				for(j=0;j<24;j++){		    
					if(infor[j].p==i+1){       //重製淘汰玩家的土地，並半價出售
						infor[j].level=0;	   //土地等級初始化 
						infor[j].p=0;		   //土地擁有者初始化
						infor[j].price=land(j)/2;//土地價格設定 
						life[i]=" D";
					}
				}                                     
			}
			 
			printf("\n");
			
			system("pause"); 
			
			printf("\n\n\n");
			
		}
		i=0;//Pn後換P1
	}
	end:
	for(i=0;i<p;i++){//遊戲結束，找出勝利著 
		if(player[i].money>0)
			printf("恭喜P%d玩家獲得最後的勝利!!!!!ˊˇˋ\n",i+1);
	}
	printf("感謝你們的遊玩");
}
