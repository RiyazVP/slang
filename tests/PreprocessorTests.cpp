#include "catch.hpp"
#include "slang.h"

using namespace slang;

namespace {

BumpAllocator alloc;
Diagnostics diagnostics;

SourceTracker& getTracker() {
    static SourceTracker* tracker = nullptr;
    if (!tracker) {
        tracker = new SourceTracker();
        tracker->addUserDirectory("../../../tests/data/");
    }
    return *tracker;
}

const Token& lexToken(const SourceText& text) {
    diagnostics.clear();
    Preprocessor preprocessor(getTracker(), alloc, diagnostics);
    preprocessor.enterFile(text);

    Token* token = preprocessor.lex();
    REQUIRE(token != nullptr);
    return *token;
}

TEST_CASE("Include File", "[preprocessor]") {
    auto& text = "`include \"include.svh\"";
    auto token = lexToken(text);

    CHECK(token.kind == TokenKind::StringLiteral);
}

void testKeyword(TokenKind kind) {
    auto text = getTokenKindText(kind);
    auto token = lexToken(SourceText::fromNullTerminated(text));

    CHECK(token.kind == kind);
    CHECK(token.toFullString() == text);
    CHECK(token.valueText() == text);
    CHECK(diagnostics.empty());
}

TEST_CASE("All Keywords", "[preprocessor]") {
    testKeyword(TokenKind::AcceptOnKeyword);
    testKeyword(TokenKind::AliasKeyword);
    testKeyword(TokenKind::AlwaysKeyword);
    testKeyword(TokenKind::AlwaysCombKeyword);
    testKeyword(TokenKind::AlwaysFFKeyword);
    testKeyword(TokenKind::AlwaysLatchKeyword);
    testKeyword(TokenKind::AndKeyword);
    testKeyword(TokenKind::AssertKeyword);
    testKeyword(TokenKind::AssignKeyword);
    testKeyword(TokenKind::AssumeKeyword);
    testKeyword(TokenKind::AutomaticKeyword);
    testKeyword(TokenKind::BeforeKeyword);
    testKeyword(TokenKind::BeginKeyword);
    testKeyword(TokenKind::BindKeyword);
    testKeyword(TokenKind::BinsKeyword);
    testKeyword(TokenKind::BinsOfKeyword);
    testKeyword(TokenKind::BitKeyword);
    testKeyword(TokenKind::BreakKeyword);
    testKeyword(TokenKind::BufKeyword);
    testKeyword(TokenKind::BufIf0Keyword);
    testKeyword(TokenKind::BufIf1Keyword);
    testKeyword(TokenKind::ByteKeyword);
    testKeyword(TokenKind::CaseKeyword);
    testKeyword(TokenKind::CaseXKeyword);
    testKeyword(TokenKind::CaseZKeyword);
    testKeyword(TokenKind::CellKeyword);
    testKeyword(TokenKind::CHandleKeyword);
    testKeyword(TokenKind::CheckerKeyword);
    testKeyword(TokenKind::ClassKeyword);
    testKeyword(TokenKind::ClockingKeyword);
    testKeyword(TokenKind::CmosKeyword);
    testKeyword(TokenKind::ConfigKeyword);
    testKeyword(TokenKind::ConstKeyword);
    testKeyword(TokenKind::ConstraintKeyword);
    testKeyword(TokenKind::ContextKeyword);
    testKeyword(TokenKind::ContinueKeyword);
    testKeyword(TokenKind::CoverKeyword);
    testKeyword(TokenKind::CoverGroupKeyword);
    testKeyword(TokenKind::CoverPointKeyword);
    testKeyword(TokenKind::CrossKeyword);
    testKeyword(TokenKind::DeassignKeyword);
    testKeyword(TokenKind::DefaultKeyword);
    testKeyword(TokenKind::DefParamKeyword);
    testKeyword(TokenKind::DesignKeyword);
    testKeyword(TokenKind::DisableKeyword);
    testKeyword(TokenKind::DistKeyword);
    testKeyword(TokenKind::DoKeyword);
    testKeyword(TokenKind::EdgeKeyword);
    testKeyword(TokenKind::ElseKeyword);
    testKeyword(TokenKind::EndKeyword);
    testKeyword(TokenKind::EndCaseKeyword);
    testKeyword(TokenKind::EndCheckerKeyword);
    testKeyword(TokenKind::EndClassKeyword);
    testKeyword(TokenKind::EndClockingKeyword);
    testKeyword(TokenKind::EndConfigKeyword);
    testKeyword(TokenKind::EndFunctionKeyword);
    testKeyword(TokenKind::EndGenerateKeyword);
    testKeyword(TokenKind::EndGroupKeyword);
    testKeyword(TokenKind::EndInterfaceKeyword);
    testKeyword(TokenKind::EndModuleKeyword);
    testKeyword(TokenKind::EndPackageKeyword);
    testKeyword(TokenKind::EndPrimitiveKeyword);
    testKeyword(TokenKind::EndProgramKeyword);
    testKeyword(TokenKind::EndPropertyKeyword);
    testKeyword(TokenKind::EndSpecifyKeyword);
    testKeyword(TokenKind::EndSequenceKeyword);
    testKeyword(TokenKind::EndTableKeyword);
    testKeyword(TokenKind::EndTaskKeyword);
    testKeyword(TokenKind::EnumKeyword);
    testKeyword(TokenKind::EventKeyword);
    testKeyword(TokenKind::EventuallyKeyword);
    testKeyword(TokenKind::ExpectKeyword);
    testKeyword(TokenKind::ExportKeyword);
    testKeyword(TokenKind::ExtendsKeyword);
    testKeyword(TokenKind::ExternKeyword);
    testKeyword(TokenKind::FinalKeyword);
    testKeyword(TokenKind::FirstMatchKeyword);
    testKeyword(TokenKind::ForKeyword);
    testKeyword(TokenKind::ForceKeyword);
    testKeyword(TokenKind::ForeachKeyword);
    testKeyword(TokenKind::ForeverKeyword);
    testKeyword(TokenKind::ForkKeyword);
    testKeyword(TokenKind::ForkJoinKeyword);
    testKeyword(TokenKind::FunctionKeyword);
    testKeyword(TokenKind::GenerateKeyword);
    testKeyword(TokenKind::GenVarKeyword);
    testKeyword(TokenKind::GlobalKeyword);
    testKeyword(TokenKind::HighZ0Keyword);
    testKeyword(TokenKind::HighZ1Keyword);
    testKeyword(TokenKind::IfKeyword);
    testKeyword(TokenKind::IffKeyword);
    testKeyword(TokenKind::IfNoneKeyword);
    testKeyword(TokenKind::IgnoreBinsKeyword);
    testKeyword(TokenKind::IllegalBinsKeyword);
    testKeyword(TokenKind::ImplementsKeyword);
    testKeyword(TokenKind::ImpliesKeyword);
    testKeyword(TokenKind::ImportKeyword);
    testKeyword(TokenKind::IncDirKeyword);
    testKeyword(TokenKind::IncludeKeyword);
    testKeyword(TokenKind::InitialKeyword);
    testKeyword(TokenKind::InOutKeyword);
    testKeyword(TokenKind::InputKeyword);
    testKeyword(TokenKind::InsideKeyword);
    testKeyword(TokenKind::InstanceKeyword);
    testKeyword(TokenKind::IntKeyword);
    testKeyword(TokenKind::IntegerKeyword);
    testKeyword(TokenKind::InterconnectKeyword);
    testKeyword(TokenKind::InterfaceKeyword);
    testKeyword(TokenKind::IntersectKeyword);
    testKeyword(TokenKind::JoinKeyword);
    testKeyword(TokenKind::JoinAnyKeyword);
    testKeyword(TokenKind::JoinNoneKeyword);
    testKeyword(TokenKind::LargeKeyword);
    testKeyword(TokenKind::LetKeyword);
    testKeyword(TokenKind::LibListKeyword);
    testKeyword(TokenKind::LibraryKeyword);
    testKeyword(TokenKind::LocalKeyword);
    testKeyword(TokenKind::LocalParamKeyword);
    testKeyword(TokenKind::LogicKeyword);
    testKeyword(TokenKind::LongIntKeyword);
    testKeyword(TokenKind::MacromoduleKeyword);
    testKeyword(TokenKind::MatchesKeyword);
    testKeyword(TokenKind::MediumKeyword);
    testKeyword(TokenKind::ModPortKeyword);
    testKeyword(TokenKind::ModuleKeyword);
    testKeyword(TokenKind::NandKeyword);
    testKeyword(TokenKind::NegEdgeKeyword);
    testKeyword(TokenKind::NetTypeKeyword);
    testKeyword(TokenKind::NewKeyword);
    testKeyword(TokenKind::NextTimeKeyword);
    testKeyword(TokenKind::NmosKeyword);
    testKeyword(TokenKind::NorKeyword);
    testKeyword(TokenKind::NoShowCancelledKeyword);
    testKeyword(TokenKind::NotKeyword);
    testKeyword(TokenKind::NotIf0Keyword);
    testKeyword(TokenKind::NotIf1Keyword);
    testKeyword(TokenKind::NullKeyword);
    testKeyword(TokenKind::OrKeyword);
    testKeyword(TokenKind::OutputKeyword);
    testKeyword(TokenKind::PackageKeyword);
    testKeyword(TokenKind::PackedKeyword);
    testKeyword(TokenKind::ParameterKeyword);
    testKeyword(TokenKind::PmosKeyword);
    testKeyword(TokenKind::PosEdgeKeyword);
    testKeyword(TokenKind::PrimitiveKeyword);
    testKeyword(TokenKind::PriorityKeyword);
    testKeyword(TokenKind::ProgramKeyword);
    testKeyword(TokenKind::PropertyKeyword);
    testKeyword(TokenKind::ProtectedKeyword);
    testKeyword(TokenKind::Pull0Keyword);
    testKeyword(TokenKind::Pull1Keyword);
    testKeyword(TokenKind::PullDownKeyword);
    testKeyword(TokenKind::PullUpKeyword);
    testKeyword(TokenKind::PulseStyleOnDetectKeyword);
    testKeyword(TokenKind::PulseStyleOnEventKeyword);
    testKeyword(TokenKind::PureKeyword);
    testKeyword(TokenKind::RandKeyword);
    testKeyword(TokenKind::RandCKeyword);
    testKeyword(TokenKind::RandCaseKeyword);
    testKeyword(TokenKind::RandSequenceKeyword);
    testKeyword(TokenKind::RcmosKeyword);
    testKeyword(TokenKind::RealKeyword);
    testKeyword(TokenKind::RealTimeKeyword);
    testKeyword(TokenKind::RefKeyword);
    testKeyword(TokenKind::RegKeyword);
    testKeyword(TokenKind::RejectOnKeyword);
    testKeyword(TokenKind::ReleaseKeyword);
    testKeyword(TokenKind::RepeatKeyword);
    testKeyword(TokenKind::RestrictKeyword);
    testKeyword(TokenKind::ReturnKeyword);
    testKeyword(TokenKind::RnmosKeyword);
    testKeyword(TokenKind::RpmosKeyword);
    testKeyword(TokenKind::RtranKeyword);
    testKeyword(TokenKind::RtranIf0Keyword);
    testKeyword(TokenKind::RtranIf1Keyword);
    testKeyword(TokenKind::SAlwaysKeyword);
    testKeyword(TokenKind::SEventuallyKeyword);
    testKeyword(TokenKind::SNextTimeKeyword);
    testKeyword(TokenKind::SUntilKeyword);
    testKeyword(TokenKind::SUntilWithKeyword);
    testKeyword(TokenKind::ScalaredKeyword);
    testKeyword(TokenKind::SequenceKeyword);
    testKeyword(TokenKind::ShortIntKeyword);
    testKeyword(TokenKind::ShortRealKeyword);
    testKeyword(TokenKind::ShowCancelledKeyword);
    testKeyword(TokenKind::SignedKeyword);
    testKeyword(TokenKind::SmallKeyword);
    testKeyword(TokenKind::SoftKeyword);
    testKeyword(TokenKind::SolveKeyword);
    testKeyword(TokenKind::SpecifyKeyword);
    testKeyword(TokenKind::SpecParamKeyword);
    testKeyword(TokenKind::StaticKeyword);
    testKeyword(TokenKind::StringKeyword);
    testKeyword(TokenKind::StrongKeyword);
    testKeyword(TokenKind::Strong0Keyword);
    testKeyword(TokenKind::Strong1Keyword);
    testKeyword(TokenKind::StructKeyword);
    testKeyword(TokenKind::SuperKeyword);
    testKeyword(TokenKind::Supply0Keyword);
    testKeyword(TokenKind::Supply1Keyword);
    testKeyword(TokenKind::SyncAcceptOnKeyword);
    testKeyword(TokenKind::SyncRejectOnKeyword);
    testKeyword(TokenKind::TableKeyword);
    testKeyword(TokenKind::TaggedKeyword);
    testKeyword(TokenKind::TaskKeyword);
    testKeyword(TokenKind::ThisKeyword);
    testKeyword(TokenKind::ThroughoutKeyword);
    testKeyword(TokenKind::TimeKeyword);
    testKeyword(TokenKind::TimePrecisionKeyword);
    testKeyword(TokenKind::TimeUnitKeyword);
    testKeyword(TokenKind::TranKeyword);
    testKeyword(TokenKind::TranIf0Keyword);
    testKeyword(TokenKind::TranIf1Keyword);
    testKeyword(TokenKind::TriKeyword);
    testKeyword(TokenKind::Tri0Keyword);
    testKeyword(TokenKind::Tri1Keyword);
    testKeyword(TokenKind::TriAndKeyword);
    testKeyword(TokenKind::TriOrKeyword);
    testKeyword(TokenKind::TriRegKeyword);
    testKeyword(TokenKind::TypeKeyword);
    testKeyword(TokenKind::TypedefKeyword);
    testKeyword(TokenKind::UnionKeyword);
    testKeyword(TokenKind::UniqueKeyword);
    testKeyword(TokenKind::Unique0Keyword);
    testKeyword(TokenKind::UnsignedKeyword);
    testKeyword(TokenKind::UntilKeyword);
    testKeyword(TokenKind::UntilWithKeyword);
    testKeyword(TokenKind::UntypedKeyword);
    testKeyword(TokenKind::UseKeyword);
    testKeyword(TokenKind::UWireKeyword);
    testKeyword(TokenKind::VarKeyword);
    testKeyword(TokenKind::VectoredKeyword);
    testKeyword(TokenKind::VirtualKeyword);
    testKeyword(TokenKind::VoidKeyword);
    testKeyword(TokenKind::WaitKeyword);
    testKeyword(TokenKind::WaitOrderKeyword);
    testKeyword(TokenKind::WAndKeyword);
    testKeyword(TokenKind::WeakKeyword);
    testKeyword(TokenKind::Weak0Keyword);
    testKeyword(TokenKind::Weak1Keyword);
    testKeyword(TokenKind::WhileKeyword);
    testKeyword(TokenKind::WildcardKeyword);
    testKeyword(TokenKind::WireKeyword);
    testKeyword(TokenKind::WithKeyword);
    testKeyword(TokenKind::WithinKeyword);
    testKeyword(TokenKind::WOrKeyword);
    testKeyword(TokenKind::XnorKeyword);
    testKeyword(TokenKind::XorKeyword);
}

}