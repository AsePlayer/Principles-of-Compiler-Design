
//Symbol table header
#include <string.h>

struct Entry
{
	int itemID;
	int used;		   // has the identifier been used?
	int arrayLength;   // if it is an array, how long is it?
	char itemName[50];  //the name of the identifier
	char itemKind[8];  //is it a function or a variable?
	char itemType[8];  // Is it int, char, etc.?
	char itemValue[50]; // the value of the identifier
	char scope[50];     // global, or the name of the function
	
	int paramsNum;	 // if it is a function, how many parameters does it have?
	int relatedVars; // if it is a function, how many variables does it use?
	int relatedVarIDs[10]; // if it is a function, what are the IDs of the variables it uses?

};

// create a struct that contains another struct
struct SymbolTable
{
	struct Entry symTabItems[100];
	struct Entry symTabScopes[100][100];
};

struct SymbolTable symTab;
int symTabIndex = 0;
int SYMTAB_SIZE = 20;

void symTabAccess(void){
	printf("::::> Symbol table accessed.\n");
}

void addItem(char itemName[50], char itemKind[8], char itemType[8], char itemValue[50], int arrayLength, char scope[50]){
	
		struct Entry newEntry;
		newEntry.itemID = symTabIndex;
		strcpy(newEntry.itemName, itemName);
		strcpy(newEntry.itemKind, itemKind);
		strcpy(newEntry.itemType, itemType);
		strcpy(newEntry.itemValue, itemValue);
		strcpy(newEntry.scope, scope);
		newEntry.arrayLength = arrayLength;
		
		// what about scope? should you add scope to this function?
		// check if scope is equal to global character array
		if(strcmp(scope, "global") == 0){
			symTab.symTabItems[symTabIndex] = newEntry;
			symTabIndex++;
		}
		else{
			// find function in symbol table (it has global scope)
			int funIndex = found(scope, "global");
			// add variable to function's relatedVarIDs array
			if(funIndex == -1){
				printf("ERROR: Function %s does not exist.\n", scope);
				return;
			}	
			// symTab.symTabItems[funIndex].relatedVarIDs[symTab.symTabItems[funIndex].relatedVars] = symTabIndex;
			// symTab.symTabItems[funIndex].relatedVars++;			
			
			// add variable to symbol table
			symTab.symTabItems[symTabIndex] = newEntry;
			symTabIndex++;
		}
	
}

void showSymTable(){
	printf(" itemID     itemName     itemKind    itemValue    itemType     ArrayLength    itemScope\n");
	printf("------------------------------------------------------------------------------------\n");
	for (int i=0; i<symTabIndex; i++){
		printf("%5d %10s %14s %10s %12s %13d %15s \n",symTab.symTabItems[i].itemID, symTab.symTabItems[i].itemName, symTab.symTabItems[i].itemKind, symTab.symTabItems[i].itemValue, symTab.symTabItems[i].itemType, symTab.symTabItems[i].arrayLength, symTab.symTabItems[i].scope);
	}
	

	printf("------------------------------------------------------------------------------------\n");
}

int found(char itemName[50], char scope[50]){
	// Lookup an identifier in the symbol table
	// what about scope?
	// return TRUE or FALSE
	// Later on, you may want to return additional information

	// Dirty loop, becuase it counts SYMTAB_SIZE times, no matter the size of the symbol table
	for(int i=0; i<SYMTAB_SIZE; i++){
		int str1 = strcmp(symTab.symTabItems[i].itemName, itemName); 
		//printf("\n\n---------> str1=%d: COMPARED: %s vs %s\n\n", str1, symTabItems[i].itemName, itemName);
		int str2 = strcmp(symTab.symTabItems[i].scope,scope); 
		//printf("\n\n---------> str2=%d: COMPARED %s vs %s\n\n", str2, symTabItems[i].itemName, itemName);
		if( str1 == 0 && str2 == 0){
			return i; // found the ID in the table
		}
	}
	return -1;
}

const char* getVariableType(char itemName[50], char scope[50]){
	//char *name = "int";
	//return name;

	for(int i=0; i<SYMTAB_SIZE; i++){
		int str1 = strcmp(symTab.symTabItems[i].itemName, itemName); 
		//printf("\n\n---------> str1=%d: COMPARED: %s vs %s\n\n", str1, symTabItems[i].itemName, itemName);
		int str2 = strcmp(symTab.symTabItems[i].scope,scope); 
		//printf("\n\n---------> str2=%d: COMPARED %s vs %s\n\n", str2, symTabItems[i].itemName, itemName);
		if( str1 == 0 && str2 == 0){
			return symTab.symTabItems[i].itemType; // found the ID in the table
		}
	}
	return NULL;
}

int getArraySize(char itemName[50], char scope[50]){
	//char *name = "int";
	//return name;

	for(int i=0; i<SYMTAB_SIZE; i++){
		int str1 = strcmp(symTab.symTabItems[i].itemName, itemName); 
		//printf("\n\n---------> str1=%d: COMPARED: %s vs %s\n\n", str1, symTabItems[i].itemName, itemName);
		int str2 = strcmp(symTab.symTabItems[i].scope,scope); 
		//printf("\n\n---------> str2=%d: COMPARED %s vs %s\n\n", str2, symTabItems[i].itemName, itemName);
		if( str1 == 0 && str2 == 0){
			return symTab.symTabItems[i].arrayLength; // found the ID in the table
		}
	}
	return NULL;
}

int compareTypes(char itemName1[50], char itemName2[50],char scope[50]){
	const char* idType1 = getVariableType(itemName1, scope);
	const char* idType2 = getVariableType(itemName2, scope);
	
	printf("%s = %s\n", idType1, idType2);
	
	int typeMatch = strcmp(idType1, idType2);
	if(typeMatch == 0){
		return 1; // types are matching
	}
	else return -1;
}

void updateItem(char itemName[50], char newItemValue[50], char scope[50]){

    // Search for the identifier in the symbol table
    int index = found(itemName, scope);

    // If the identifier is found in the symbol table, update its value
    if (index >= 0) {
        strcpy(symTab.symTabItems[index].itemValue, newItemValue);
    } else {
        // If the identifier is not found in the symbol table, add it to the symbol table
        addItem(itemName, "variable", "unknown", newItemValue, 0, scope);
    }
}

// Make a function like updateItem but it updates based on id
void updateItemByID(int itemID, char newItemValue[50]){
	// If the identifier is found in the symbol table, update its value
	if (itemID >= 0) {
		strcpy(symTab.symTabItems[itemID].itemValue, newItemValue);
	} else {
		// If the identifier is not found in the symbol table, add it to the symbol table
		printf("ERROR: Item not found in symbol table.\n");
	}
}

const char * getValue(int itemID){
	if(itemID == -1 || itemID > symTabIndex){
		printf("ERROR: Item not found in symbol table.\n");
		return NULL;
	}
	//printf("found value: %s\n", symTab.symTabItems[itemID].itemValue);
	return symTab.symTabItems[itemID].itemValue;
}
