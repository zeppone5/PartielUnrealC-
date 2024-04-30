// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Partiel : ModuleRules
{
	public Partiel(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
