#include "Proyectil.h"
// Fill out your copyright notice in the Description page of Project Settings.


#include "Proyectil.h"
#include "UObject/ConstructorHelpers.h"
#include "Materials/Material.h"

// Sets default values
AProyectil::AProyectil()
{
	PrimaryActorTick.bCanEverTick = true;

	ProyectilMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProyectilMesh"));
	RootComponent = ProyectilMesh;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> ProyectilMeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));
	if (ProyectilMeshAsset.Succeeded())
	{
		ProyectilMesh->SetStaticMesh(ProyectilMeshAsset.Object);
		ProyectilMesh->SetWorldScale3D(FVector(1.0f)); // Ajusta el tamaño según sea necesario
		ProyectilMesh->SetMaterial(0, LoadObject<UMaterial>(nullptr, TEXT("Material'/Game/StarterContent/Materials/M_Metal_Gold.M_Metal_Gold'")));
	}
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
	ProjectileMovement->UpdatedComponent = ProyectilMesh;
	ProjectileMovement->InitialSpeed = 100.f; // Velocidad inicial lenta
	ProjectileMovement->MaxSpeed = 100.f; // Velocidad máxima
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = true;
	ProjectileMovement->Bounciness = 0.3f;
	ProjectileMovement->ProjectileGravityScale = 0.0f; // Sin gravedad
}

void AProyectil::Initialize(const FVector& Direction)
{
	ProjectileMovement->Velocity = Direction * ProjectileMovement->InitialSpeed;
}

// Called when the game starts or when spawned
void AProyectil::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProyectil::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

