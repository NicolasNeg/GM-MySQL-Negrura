#define RECORDING "prueba0" //Aqui ponemos el nombre del arvhivo que grabaste
#define RECORDING_TYPE 2  //<<--- Aqui va un 1 si tu NPC es en vehículo y un 2 si es a Pie

#include <a_npc>
    main(){}
    public OnRecordingPlaybackEnd() StartRecordingPlayback(RECORDING_TYPE, RECORDING); //Aquí lo que hacemos es que cuando se acabe la grabación de tu NPC vuelva a empezar, quítalo si no quieres que esto pase

    #if RECORDING_TYPE == 1  // Si es en vehiculo se cumple esto
        public OnNPCEnterVehicle(vehicleid, seatid) StartRecordingPlayback(RECORDING_TYPE, RECORDING); //Aquí lo que hacemos es que cuando el NPC entre a su vehículo empieze la grabación que existe
        public OnNPCExitVehicle() StopRecordingPlayback(); //Aquí lo que hacemos es que cuando el NPC salga del vehículo termine la grabación
    #else // Sino es en vehiculo solo se cumple esto
        public OnNPCSpawn() StartRecordingPlayback(RECORDING_TYPE, RECORDING); //Aquí lo que hacemos es que cuando el NPC aparezca empieze a hacer su recorrido
       #endif
