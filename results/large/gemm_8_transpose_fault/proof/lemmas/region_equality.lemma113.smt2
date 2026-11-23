; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_1 () (_ BitVec 32))
(declare-fun arg0_17 () (_ BitVec 32))
(declare-fun arg1_8 () (_ BitVec 32))
(assert
 (let ((?x72897 (bvmul arg0_17 arg1_1)))
(let ((?x64302 (bvmul (_ bv4294967295 32) ?x72897)))
(let ((?x45160 (bvmul arg0_17 arg1_8)))
(let ((?x68598 (bvadd ?x45160 ?x64302)))
(and (distinct ?x68598 (_ bv0 32)) true))))))
(check-sat)
