
#include "list.h"
#include "operation.h"
#include "my_data.h"
 

void insertAndSort(List &L, infotype x) {
    /**
    * IS : List may be empty
    * PR : insert a new element into an already sorted-by-ID List L
    *      so that the elements inside List L is still sorted by ID.
    *      procedure must also check if such ID is already exists (No Duplicate ID).
    *      If new data has duplicate ID, new data is rejected.
    * FS : elements in List L sorted by ID, P is inside List L
    */

    address Prec, P;
    //-------------your code here-------------
    if (findElm(L, x) != nullptr) {
        cout << "ID " << x.ID << " already exists, data rejected" << endl;
        return;
    }

    P = allocate(x);
    if (L.first == nullptr || x.ID < L.first->info.ID) {
        insertFirst(L, P);
    } else {
        Prec = L.first;
        while (Prec->next != nullptr && Prec->next->info.ID < x.ID) {
            Prec = Prec->next;
        }
        insertAfter(L, Prec, P);
    }
    //----------------------------------------
}


void deletebyID(List &L, int id_x) {
    /**
    * IS : List L may be empty
    * FS : an element with ID info = id_x is deleted from List L (deallocate)
    */

    address Prec, P;
    //-------------your code here-------------
    P = L.first;
    while (P != nullptr && P->info.ID != id_x) {
        P = P->next;
    }

    if (P == nullptr) {
        cout << "Data not found" << endl;
        return;
    }

    if (P == L.first) {
        deleteFirst(L, P);
    } else if (P == L.last) {
        deleteLast(L, P);
    } else {
        Prec = P->prev;
        deleteAfter(L, Prec, P);
    }
    deallocate(P);
    cout << "Data deleted" << endl;
    //----------------------------------------
}


void savePassedMember(List &L, List &L2){
    /**
    * IS : List L and L2 may be empty
    * FS : any element with score greater than 80 is moved to L2
    */
    address P, Q, Next;
    //-------------your code here-------------
    P = L.first;
    while (P != nullptr) {
        Next = P->next;
        if (P->info.score > 80) {
            if (P == L.first) {
                deleteFirst(L, Q);
            } else if (P == L.last) {
                deleteLast(L, Q);
            } else {
                deleteAfter(L, P->prev, Q);
            }
            insertLast(L2, Q);
        }
        P = Next;
    }
    //----------------------------------------
}
