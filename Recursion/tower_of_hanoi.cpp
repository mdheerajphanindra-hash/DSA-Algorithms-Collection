#include <iostream>
#include <cmath>
using namespace std;

struct Stack {
    int items[64];
    int top;
};

void push(Stack* s, int item) {
    s->top++;
    s->items[s->top] = item;
}

int pop(Stack* s) {
    if (s->top == -1)
        return -1;
    return s->items[s->top--];
}

void moveDisk(char from, char to, int disk) {
    cout << disk << " " << from << " " << to << endl;
}

void moveDisksBetweenPoles(Stack* from, Stack* to, char f, char t) {
    int fromTop = (from->top == -1) ? -1 : from->items[from->top];
    int toTop = (to->top == -1) ? -1 : to->items[to->top];

    if (fromTop == -1) {
        int disk = pop(to);
        push(from, disk);
        moveDisk(t, f, disk);
    }
    else if (toTop == -1) {
        int disk = pop(from);
        push(to, disk);
        moveDisk(f, t, disk);
    }
    else if (fromTop > toTop) {
        int disk = pop(to);
        push(from, disk);
        moveDisk(t, f, disk);
    }
    else {
        int disk = pop(from);
        push(to, disk);
        moveDisk(f, t, disk);
    }
}

void iterativeHanoi(int num_disks, char initial_peg, char destination_peg, char intermediate_peg) {
    Stack initial, destination, intermediate;
    initial.top = destination.top = intermediate.top = -1;

    int total_moves = pow(2, num_disks) - 1;

    if (num_disks % 2 == 0) {
        char temp = destination_peg;
        destination_peg = intermediate_peg;
        intermediate_peg = temp;
    }

    for (int i = num_disks; i >= 1; i--)
        push(&initial, i);

    for (int i = 1; i <= total_moves; i++) {
        if (i % 3 == 1)
            moveDisksBetweenPoles(&initial, &destination, initial_peg, destination_peg);
        else if (i % 3 == 2)
            moveDisksBetweenPoles(&initial, &intermediate, initial_peg, intermediate_peg);
        else
            moveDisksBetweenPoles(&intermediate, &destination, intermediate_peg, destination_peg);
    }
}

int main() {
    int n;
    cin >> n;

    iterativeHanoi(n, 'A', 'C', 'B');

    return 0;
}
