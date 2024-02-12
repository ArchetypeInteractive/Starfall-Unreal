// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Starfall : ModuleRules
{
	public Starfall(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] 
			{
                "Core",
                "CoreUObject",
                "Engine",
                "InputCore",
                "EnhancedInput",
                "UMG",
                "Slate",
                "SlateCore",
                "Json",
                "JsonUtilities"
            }
		);

        PrivateDependencyModuleNames.AddRange(new string[]
		{
				"NakamaUnreal",
				"NakamaCore",
				"GameplayAbilities",
				"GameplayTags",
				"GameplayTasks",
		}
	);
    }
}
