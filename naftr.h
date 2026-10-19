#ifndef NAFTR_H
#define NAFTR_H

int selectOutputPort(
    int currentID,
    int destinationID,
    int numColumns,
    int inPort,
    int busy[],
    int congested[],
    int faulty[]
);

#endif
