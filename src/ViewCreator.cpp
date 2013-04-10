
#include "ViewCreator.h"


void ViewCreator::Run ( void ) {
    cout << __FILE__ << __LINE__ << endl;
    createDir ( "gendir" );
    cout << __FILE__ << __LINE__ << endl;
    writingFile ( "gendir/gentext.txt", "Hallo Welt!");
    cout << __FILE__ << __LINE__ << endl;
    
}