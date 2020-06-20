// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomTextFileManager.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"
#include "HAL/PlatformFilemanager.h"


bool UCustomTextFileManager::SaveArrayText(FString SaveDirectory, FString FileName, TArray<FString> SaveText, bool AllowOverWriting = false)
{
	//Set complete file path for the quest saving.
	SaveDirectory += "\\";
	SaveDirectory += FileName;

	if (!AllowOverWriting)
	{
		if(FPlatformFileManager::Get().GetPlatformFile().FileExists(*SaveDirectory))
		{
			return false;
		}
	}

	FString FinalString = "";
	for (FString& Each : SaveText)
	{
		FinalString += Each;
		FinalString += LINE_TERMINATOR;
	}
	FFileHelper::SaveStringToFile(FinalString, *SaveDirectory);
	return false;
	//return FFileHelper::SaveStringToFile(FinalString, *SaveDirectory);
}