#define RECORDING "prueba0" //Aqui ponemos el nombre del arvhivo que grabaste
#define RECORDING_TYPE 2  //<<--- Aqui va un 1 si tu NPC es en veh�culo y un 2 si es a Pie

#include <a_npc>
    main(){}
    public OnRecordingPlaybackEnd() StartRecordingPlayback(RECORDING_TYPE, RECORDING); //Aqu� lo que hacemos es que cuando se acabe la grabaci�n de tu NPC vuelva a empezar, qu�talo si no quieres que esto pase

    #if RECORDING_TYPE == 1  // Si es en vehiculo se cumple esto
        public OnNPCEnterVehicle(vehicleid, seatid) StartRecordingPlayback(RECORDING_TYPE, RECORDING); //Aqu� lo que hacemos es que cuando el NPC entre a su veh�culo empieze la grabaci�n que existe
        public OnNPCExitVehicle() StopRecordingPlayback(); //Aqu� lo que hacemos es que cuando el NPC salga del veh�culo termine la grabaci�n
    #else // Sino es en vehiculo solo se cumple esto
        public OnNPCSpawn() StartRecordingPlayback(RECORDING_TYPE, RECORDING); //Aqu� lo que hacemos es que cuando el NPC aparezca empieze a hacer su recorrido
       #endif
