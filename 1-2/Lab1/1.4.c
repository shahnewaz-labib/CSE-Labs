#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char name[80];
    scanf("%d", &n);
    int nifty = 0, sartaj = 0;
    while(n--) {
        scanf("%s", name);
        if(!strcmp(name, "Adham")) nifty++;
        else sartaj++;
    }
    if(nifty > sartaj) printf("Adham was the imposter."); // Changed the texts :)
    else if(sartaj > nifty) printf("Sartaj was the imposter.");
    else printf("No one was ejected. (Tie)"); 
}
