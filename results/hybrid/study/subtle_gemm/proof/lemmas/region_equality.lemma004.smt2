; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_4 () (_ BitVec 32))
(declare-fun arg0_0 () (_ BitVec 32))
(declare-fun arg1_1 () (_ BitVec 32))
(assert
 (let ((?x340418 (bvmul arg0_0 arg1_4)))
(let ((?x332747 (bvmul (_ bv4294967295 32) ?x340418)))
(let ((?x356703 (bvmul arg0_0 arg1_1)))
(let ((?x304220 (bvadd ?x356703 ?x332747)))
(and (distinct ?x304220 (_ bv0 32)) true))))))
(check-sat)
