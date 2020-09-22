#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char name[80];
    scanf("%d", &n);
    int nifty = 0, sartaj = 0;
    for(int i = 0; i < n; i++) {
        scanf("%s", name);
        if(!strcmp(name, "Adham")) nifty++;
        else sartaj++;
    }
    if(nifty > sartaj) printf("Adham");
    else if(sartaj > nifty) printf("Sartaj");
    else printf("No one was ejected. (Tie)"); // Changed the text :)
}
