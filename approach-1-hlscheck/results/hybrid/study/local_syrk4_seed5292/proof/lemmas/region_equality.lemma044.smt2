; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_6 () (_ BitVec 32))
(declare-fun arg0_13 () (_ BitVec 32))
(declare-fun arg0_9 () (_ BitVec 32))
(assert
 (let ((?x527060 (bvmul arg0_13 arg0_6)))
(let ((?x3499 (bvmul (_ bv4294967295 32) ?x527060)))
(let ((?x488547 (bvmul arg0_13 arg0_9)))
(let ((?x473484 (bvadd ?x488547 ?x3499)))
(and (distinct ?x473484 (_ bv0 32)) true))))))
(check-sat)
