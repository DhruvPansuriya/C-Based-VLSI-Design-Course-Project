; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_57 () (_ BitVec 32))
(declare-fun arg0_17 () (_ BitVec 32))
(declare-fun arg1_15 () (_ BitVec 32))
(assert
 (let ((?x72914 (bvmul arg0_17 arg1_57)))
(let ((?x58981 (bvmul (_ bv4294967295 32) ?x72914)))
(let ((?x30547 (bvmul arg0_17 arg1_15)))
(let ((?x66753 (bvadd ?x30547 ?x58981)))
(and (distinct ?x66753 (_ bv0 32)) true))))))
(check-sat)
