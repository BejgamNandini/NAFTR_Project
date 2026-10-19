#ifndef ARS_H
#define ARS_H

int adaptiveRoutingDecision(
    int currentID,
    int destinationID,
    int numColumns,
    int inPort,
    int busy[],
    int congested[],
    int faulty[]
);

#endif