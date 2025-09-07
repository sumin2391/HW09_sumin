// Fill out your copyright notice in the Description page of Project Settings.


#include "LXPlayerState.h"
#include "Net/UnrealNetwork.h"

ALXPlayerState::ALXPlayerState()
	: PlayerNameString(TEXT("None"))
	, CurrentGuessCount(0)
	, MaxGuessCount(5)
{
	bReplicates = true;
}

void ALXPlayerState::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ALXPlayerState, PlayerNameString);
	// DOREPLIFETIME(ThisClass, PlayerNameString); 이거도 됨, 아래것들도 위와같이 할 수 있나봄
	DOREPLIFETIME(ThisClass, CurrentGuessCount);
	DOREPLIFETIME(ThisClass, MaxGuessCount);
}

FString ALXPlayerState::GetPlayerInfoString()
{
	FString PlayerInfoString = PlayerNameString + TEXT("(") + FString::FromInt(CurrentGuessCount) + TEXT("/") + FString::FromInt(MaxGuessCount) + TEXT(")");
	return PlayerInfoString;
}
