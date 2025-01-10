plugins {
    kotlin("jvm") version "1.8.0"
    id("io.ktor.plugin") version "2.3.1"
}

dependencies {
    implementation("io.ktor:ktor-server-core:2.3.1")
    implementation("io.ktor:ktor-server-netty:2.3.1")
    implementation("io.ktor:ktor-server-content-negotiation:2.3.1")
    implementation("io.ktor:ktor-serialization-kotlinx-json:2.3.1")
    testImplementation("io.ktor:ktor-server-tests:2.3.1")
}
