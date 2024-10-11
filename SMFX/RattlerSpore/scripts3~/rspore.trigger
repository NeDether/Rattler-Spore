##############################
#### RSPORE_VaultDetector ####
##############################

state RSPORE_VaultDetector
    letterbox -on
   pauseGame
   mixevent space_cin_start 1
    addActor "ufo" ufo
    startcamera -target "ufo" -targetOffset (0, 0, 0) -ease -follow -offset 20 -noWait -duration .75
    wait -secs .75
    nextState RSPORE_VaultDetector2
end

state RSPORE_VaultDetector2
   startEffect "detection" RSPORE_ufo_radar_incoming_ratal -target "ufo" -attached -noWait
    wait -secs 2
    nextState RSPORE_VaultDetector3
end

state RSPORE_VaultDetector3
   startcamera -target "planet" -targetOffset (0, 0, 0) -ease -offset 8 -follow -duration 1.5 -noWait -anchored
   wait -secs 1.5
   nextState RSPORE_VaultDetector4
end

state RSPORE_VaultDetector4
   pauseGame -screenEffect -pauseGraphics
   wait -secs .135
   nextState RSPORE_VaultDetector5
end

state RSPORE_VaultDetector5
   text "SkibidiSkibdi" rspore-cutscenes!0x00000000
   wait -secs 1
   nextState SPG_MomentButtonSnap
end

####

#########################
#### RSPORE_VAULTCUT ####
#########################

state RSPORE_VAULTCUT
   addActor "Rare" rare
   addActor "ufo" ufo
   toggleplumping "Rare" false
   letterbox -on
   mixevent space_cin_start 1
   startEffect "detection" RSPORE_ufo_radar_incoming_ratal -target "ufo" -attached -noWait
   startcamera -target "ufo" -targetOffset (0, 0, 0) -offset 7 -useFootprint -noWait -follow -duration .5 -ease
   wait -secs 2
   nextState RSPORE_VAULTCUTA1
end   

state RSPORE_VAULTCUTA1
   pauseGame -screenEffect -pauseGraphics
   stopCamera
   wait -secs .135
   nextState RSPORE_VAULTCUTA2
end

state RSPORE_VAULTCUTA2
   wait -secs 1
   text "SPG_Rare2" rspore-cutscenes!0x00000001
   nextState RSPORE_VAULTCUTA3
end

state RSPORE_VAULTCUTA3
   wait -forNext
   nextState RSPORE_VAULTCUTA4
end   

state RSPORE_VAULTCUTA4
   unpauseGame
   text -hide
   startEffect "radarMode" radarMode -noWait   
   startcamera -targetpos (0, 0, 0) -targetOffset (0, 0, 0) -noWait -duration .25 -anchored
   wait -secs .25
   nextState RSPORE_VAULTCUTA
   startsound sfx_cin_spg_detect_object -escstop
end   

state RSPORE_VAULTCUTA
   startcamera -target "Rare" -targetOffset (0, 0, 0) -noWait -satellite -fov .9  -duration 3 -ease
   nextState RSPORE_VAULTCUTB
   wait -secs 3
end

state RSPORE_VAULTCUTB
   startcamera -target "Rare" -targetOffset (0, 0, 0) -noWait -offset 7 -fov .5 -useRadius -duration 3 -ease
   wait -secs 3
   nextState RSPORE_VAULTCUTC
end   

state RSPORE_VAULTCUTC
   startcamera -target "Rare" -targetOffset (0, 0, 4) -noWait -offset 5 -pitch .15 -fov .7 -useRadius -duration 2 -ease
   wait -secs 2
   nextState RSPORE_VAULTCUT2
end   

state RSPORE_VAULTCUT2
   pauseGame -screenEffect -effect radarModeFreeze -pauseGraphics
   stopCamera
   wait -secs .135
   nextState RSPORE_VAULTCUT3
end

state RSPORE_VAULTCUT3
   wait -secs 1
   text "SPG_Rare2" rspore-cutscenes!0x00000002
   toggleplumping "Rare" true
   nextState SPG_MomentButtonSnap
end   

####

##############################################
#### RSPORE_VAULTSETI ####
##############################################

state RSPORE_VAULTSETIWAIT
	letterbox -on
	wait -secs 3
	nextState RSPORE_VAULTSETI
end

state RSPORE_VAULTSETI
    letterbox -on
    mixevent space_cin_start 1
    addActor "ufo" ufo
    toggleplumping "ufo" false
   startEffect "detection" RSPORE_ufo_radar_incoming_ratal_galaxy -target "ufo" -attached -noWait
   startcamera -target "ufo" -targetOffset (0, 0, 0) -useFootprint -offset 7 -nearClip .05 -noWait -follow -duration 1.5 -ease
    wait -secs 2
    nextState RSPORE_VAULTSETIB
end

state RSPORE_VAULTSETIB
  ### startcamera -target "cachedStar" -targetOffset (0, 0, 0) -anchored  -noWait -nearClip .05 -ease -duration 1 ######
   wait -secs 2
   nextState RSPORE_VAULTSETIC
end

state RSPORE_VAULTSETIC
   pauseGame -screenEffect -pauseGraphics
   wait -secs .135
   nextState RSPORE_VAULTSETID
end

state RSPORE_VAULTSETID
    text "SPG_SETI" rspore-cutscenes!0x00000004
   wait -secs 1
   nextState SPG_MomentButton
end

####