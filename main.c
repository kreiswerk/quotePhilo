#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <stdint.h>

//Aviable Phils
#define ROUSSEAU 0
#define NIETSCHE 1
#define SOCRATES 2
#define KANT 3
#define CONFUZIUS 4

//this comment is only here to check if i can push to upstream

void printPhilosophers();
int assertSelectionToPhil(char *selection);
void printRandomQuote(uint16_t selection);

char *philosophers[] = {"Rousseau", "Nietsche", "Socrates", "Kant", "Confuzius"};

char *quotesRousseau[] = {"with enough leverage, a finger could overturn the world, but to support the world, one must have the shoulders of Hercules\n", "the world of reality has its limits, the world of imagination is boundless\n", "there is not one evildoer who could not be made good for something\n", "Man is born free, and everywhere he is in chains\n", "there is no subjection as perfect as that which keeps the appearance of freedom\n", "the right of conquest has no foundation than the right of the strongest\n", "the strongest is never strong enough to always be the master, unless he transforms that strength into right\n", "insults are arguments who are in the wrong\n", "what wisdom can you find thats greater than kindness ?\n", "falsehood has an infinity of combinations, but truth only has one mode of being\n", "its not possible for minds degraded by a host of trivial concerns to ever rise up to anything great\n", "you forget that the fruits belong to all and the land belongs to noone\n", "we are reduced to ask others what we are. we never dare to ask ourselfs\n", "patience is bitter, but the fruit is sweet\n", "i would rather be a man of paradoxes, than a man of prejudices\n", "absolute silence leads to to sadness. it is the image of death\n", "it is when a state is in decay that the multitude of crimes is a guarantee of impunity\n", "if im in a group of a 100 people, do 99 have the right to sentence me to death, just because they are majority\n", "civilization is a hopeless race to discover remedies for the evil it produces\n"};


char *quotesNietsche[] = {"there are two different types of people in the world, those who want to know, and those who want to believe\n", "sometimes people dont want to hear the truth because they dont want their illusions to be destroyed\n", "there will always be stumbling stones in the road ahead of us. they will be stumbling blocks or stepping stones, it all depends on how you use them\n", "nobody is more inferior than those who insist on being equal\n", "and those who were seen dancing were thought to be insane by those wo could not hear the music\n", "to live is to suffer, to survive is to find some meaning in the suffering\n", "you have your way. i have my way. as for the right way, the correct way, and the only way, it does not exist\n", "our greatest experiences are our quietest moments\n", "im not upset you lied to me, im upset that from now on i cant trust you\n", "whoever fights monsters should see to it that in the process he does not become a monster. and if you gaze long enough into the abyss, the abyss will glaze back at you\n", "the tree that would grow to heaven must send its roots to hell\n", "to predict the behaviour of ordinary people, you only have to assume that they always will try to escape a disagreeable situation with the smallest possible expenditure of intelligence\n", "do you want to have an easy life ? then always stay with the head and lose yourself in the heard\n", "i know no better life purpose than to perish in attempting the great and the impossible\n", "the higher we soar the smaller we appear to those who cannot fly\n", "invisible threads are the strongest ties\n", "there are no facts, only interpretations\n"};

char *quotesSocrates[] = {"falling down is not failure. failure comes when you stay where you have fallen\n", "when a debate is lost, slander becomes the tool of the looser\n", "awareness of ignorance is the beginning of wisdom\n", "the secret of happiness, you see is not found in seeking more, but in developing the capacity to enjoy less\n", "true wisdom comes to each of us when we realize how little we understand about life, ourselves, and the world around us\n", "The easiest and noblest way is not to be crushing others, but to be improving yourselves\n", "I don't care what people say about me. I do care about my mistakes\n", "If you want to be wrong then follow the masses\n", "Most people, including ourselves, live in a world of relative ignorance. We are even comfortable with that ignorance, because it is all we know. When we first start facing truth, the process may be frightening, and many people run back to their old lives. But if you continue to seek truth, you will eventually be able to handle it better. In fact, you want more! It's true that many people around you now may think you are weird or even a danger to society, but you don't care. Once you've tasted the truth, you won't ever want to go back to being ignorant\n", "It is better to make a mistake with full force of your being than to carefully avoid mistakes with a trembling spirit\n", "In every person there is a sun. Just let them shine\n", "When a woman is allowed to become a man's equal, she becomes his superior\n", "Sometimes you have to let go to see if there was anything worth holding onto\n", "Silence is a profound melody, for those who can hear it above all the noise\n", "The years wrinkle our skin, but lack of enthusiasm wrinkles our soul\n"};

char *quotesKant[] = {"It is beyond a doubt that all our knowledge that begins with experience\n", "All our knowledge begins with the senses, proceeds then to the understanding, and ends with reason. There is nothing higher than reason\n", "I had to deny knowledge in order to make room for faith\n", "Thoughts without content are empty, intuitions without concepts are blind\n", "Two things fill the mind with ever new and increasing wonder and awe-the starry heavens above me, and the moral law within me\n", "Live your life as though your every act were to become a universal law\n", "Man must be disciplined, for he is by nature raw and wild\n", "Enlightenment is man's release from his self-incurred tutelage. Tutelage is man's inability to make use of his understanding without direction from another\n", "We are not rich by what we possess but by what we can do without\n", "An action, to have moral worth, must be done from duty\n", "All our knowledge begins with the senses, proceeds then to the understanding, and ends with reason. There is nothing higher than reason\n", "If man makes himself a worm he must not complain when he is trodden on\n"};

int main(int args, char **argv)
{

    printf("Nietsche: %i", (sizeof(quotesNietsche)/sizeof(char*)));
    printf("Rousseau: %i", (sizeof(quotesRousseau)/sizeof(char*)));
    printf("Socrates: %i", (sizeof(quotesSocrates)/sizeof(char*)));
    printf("Kant: %i", (sizeof(quotesKant)/sizeof(char*)));
    if(args > 2)
    {
        printf("Your selection is not valid, too many arguments supplied\n");
        //same as no argument supplied but included warning
    }
    else if(args > 1)
    {
        int philosopher = assertSelectionToPhil(argv[1]);
        if(philosopher >= 0)
        {
           printRandomQuote(philosopher); 
        }
        else
        {
            printf("Your selection is invalid\n"); 
        }
    }
    else
    {
        printPhilosophers();
        
    }
    
//   printf("Qutoes: %i\n", sizeof(quotesRousseau)/sizeof(char*));
//   printf("Qutoes: %i\n", sizeof(quotesNietsche)/sizeof(char*));
//   printf("Qutoes: %i\n", sizeof(quotesSocrates)/sizeof(char*));
}



void printPhilosophers()
{
    printf("Select from the following philosophers:\n");
    uint16_t philosopherCount = sizeof(philosophers)/sizeof(char*);
    
    for(int i = 0; i < philosopherCount; i++)
    {
        printf("\t-> %s\n", philosophers[i]);
    }
}

int assertSelectionToPhil(char *selection)
{
    uint16_t philosopherCount = sizeof(philosophers)/sizeof(char*);
    for(uint16_t i = 0; i < philosopherCount; i++)
    {
        if(strcmp(philosophers[i], selection) == 0)
        {
            return i;
        }
    }
    return -1;
}

void printRandomQuote(uint16_t selection)
{
    uint8_t quoteCount = 0;
    uint16_t index;
    time_t t;

    srand((unsigned) time(&t));

    switch (selection){
                 
        case ROUSSEAU:
                quoteCount = sizeof(quotesRousseau)/sizeof(char*);
                index = rand() % quoteCount;
                printf("%s\n", quotesRousseau[index]);      
                break;

        case NIETSCHE:
                quoteCount =  sizeof(quotesNietsche)/sizeof(char*);             
                index = rand() % quoteCount;
                printf("%s\n", quotesNietsche[index]);      
                break;

        case SOCRATES:
                quoteCount =  sizeof(quotesSocrates)/sizeof(char*);             
                index = rand() % quoteCount;
                printf("%s\n", quotesSocrates[index]);      
                break;
        
        case KANT:
                quoteCount =  sizeof(quotesKant)/sizeof(char*);             
                index = rand() % quoteCount;
                printf("%s\n", quotesKant[index]);      
                break;

        default: 
                printf("oops something must have gone wrong\n");
                break;
    }
}
