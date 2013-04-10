
#include "ViewCreator.h"


void ViewCreator::Run ( void ) {
    createDir ( "gendir" );
    writingFile ( "gendir/gentext.txt", "Hallo Welt!");
    
}